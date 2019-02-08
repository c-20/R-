#include "code.h"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

#define Rdrive   main
#define Rfolder  "/R:/"
#define RDRIVELIST	{ "R:", NULL }   // "S:", NULL }


#define UGERDWREX 12
#define URD 0
#define GRD 1 
#define ERD 2 
#define UGEGAP1   3
#define UWR 4 
#define GWR 5
#define EWR 6
#define UGEGAP2   7
#define UEX 8
#define GEX 9
#define EEX 10
#define UGEEND    11

#include "utf8char.h"

typedef struct _TAG {
  CS tag;
  IN index;
  struct _TAG *next;
} TAG;


VD frameheaderfoot() {
  LORN1s("Cache-Control: ", "max-age=0, must-revalidate");
  LORN1s("Pragma: ", "no-cache");
  LORN("");
}

VD frametextheader() {
  LORN1s("Content-Type: ", "text/plain; charset=utf-8");
  frameheaderfoot();
}

VD framehtmlheader() {
  LORN1s("Content-Type: ", "text/html; charset=utf-8");
  frameheaderfoot();
}
VD framedownloadheader(CS filename) {
  LORN1s("Content-Type: ", "application/octet-stream");
  LORN2s("Content-Disposition: ", "attachment; filename=", filename);
  LORN1s("Content-Transfer-Encoding: ", "binary");
  LORN1s("Accept-Ranges: ", "bytes");
  frameheaderfoot();
}
VD framedataheaderhead(CS mimetype, IN contentlen) {
  LORN1s("Content-Type: ", mimetype);
  LORN1i("Content-Length: ", contentlen);
  LORN1s("Content-Encoding: ", "identity");
  LORN1s("Accept-Ranges: ", "bytes");
//  LORN1s("Content-Transfer-Encoding: ", "binary");
}

IN framefulldataheader(CS mimetype, IN contentlen) {
  framedataheaderhead(mimetype, contentlen);
  frameheaderfoot();
  RT contentlen; // indicates how many bytes to read
}

IN framepartdataheader(CS mimetype, IN rangestart, IN rangestop, IN totallen) {
  LORN("Status: 206 Partial Content");
  IF (rangestart GQ totallen OR rangestart LT 0) {
    rangestart = totallen;    // invalid range
    rangestop = totallen - 1; // return 0 bytes
  } // return nothing if invalid start index given
  IF (rangestop GQ totallen OR rangestop LT rangestart) {
    rangestart = totallen;    // invalid or backward range
    rangestop = totallen - 1; // return 0 bytes
  } // return nothing if invalid stop index given
  IN rangelen = rangestop - rangestart + 1;
  framedataheaderhead(mimetype, rangelen);
  LORN3F("Content-Range: bytes %d-%d/%d", rangestart, rangestop, totallen);
  frameheaderfoot();
  RT rangelen; // indicates 0 bytes should be read if range is invalid
}

VD framehtmlincludestyle() {
      printf("<style>\n");
      printf("  html, body { margin: 0; padding: 0; overflow: hidden;\n");
      printf("               font-size: 10px; line-height 12px; }\n");
      printf("  .tree { height: 100%; overflow-x: auto; overflow-y: hidden;");
      printf("          font-size: 0; background-color: #ccc; white-space: nowrap; }\n");
      printf("  .tree::-webkit-scrollbar { background: #bbb; height: 10px; }\n");
      printf("  .tree::-webkit-scrollbar-thumb { background: #555; border-radius: 6px;\n");
      printf("            border: #555 inset 1px; }\n");
      printf("  .dir { display: inline-block; padding: 0; height: 100%;");
      printf("            overflow-x: hidden; overflow-y: scroll;\n");
      printf("            border-right: #111 solid 1px; font-size: 14px; line-height: 16px; }\n");
      printf("  .dir::-webkit-scrollbar { background: #bbb; width: 10px; }\n");
      printf("  .dir::-webkit-scrollbar-thumb { background: #888; border-radius: 6px;\n");
      printf("            border: #555 inset 1px; }\n");
      printf("  .dir > div { padding: 0 4px; font-size: 14px; line-height 16px; }\n");
      printf("  .dir > div > div.suffix > u { line-height 16px; text-decoration: none; }\n");
      printf("  .dir > div > div.suffix > u:hover { cursor: pointer; color: #fc3; }\n");
      printf("  .dir > .file          { width: 100%; }\n");
      printf("  .dir > .file:hover    { cursor: pointer; background-color: #fc3; }\n");
      printf("  .dir > .filesel       { width: 100%; font-weight: bold; background-color: #eb2; color: #eee; }\n");
      printf("  .dir > .dlfile        { width: 100%; font-weight: bold; background-color: #1b1; color: #b2b; }\n");
      printf("  .dir > .dlfilesel     { width: 100%; font-weight: normal; background-color: #eb2; color: #d1d; }\n");
      printf("  .dir > .link          { width: 100%; font-style: italic; }\n");
      printf("  .dir > .link:hover    { cursor: pointer; background-color: #0cc; }\n");
      printf("  .dir > .linksel       { width: 100%; font-weight: bold; background-color: #0bb; color: #4ee; }\n");
      printf("  .dir > .subdir        { width: 100%; font-weight: bold; text-align: right; }\n");
      printf("  .dir > .subdir:hover  { cursor: pointer; background-color: #77e; }\n");
      printf("  .dir > .subdirsel     { width: 100%; font-weight: bold; background-color: #66b;\n");
      printf("                          color: #fff; text-align: right; }\n");
      printf("  .dir > .subdirsel > .suffix { color: #77e; }\n");
      printf("  .dir > .subdirdeetsel { width: 100%; font-weight: bold; background-color: #55a;\n");
      printf("                          color: #eee; text-align: right; }\n");
      printf("  .dir > .subdirdeetsel > .suffix { color: #4ee; }\n");
      printf("  .dir > .special       { width: 100%; font-weight: bold; color: #c77; }\n");
      printf("  .dir > .special:hover { cursor: cross; background-color: #777; }\n");
      printf("  .dir > .specialsel    { width: 100%; font-weight: bold; background-color: #b66; color: #f00; }\n");
      printf("  .dir > div > .suffix  { float: right; padding: 0 6px; }\n");
      printf("  .view   { display: inline-block; padding: 0; height: 100%;");
      printf("            overflow-x: hidden; overflow-y: scroll;\n");
      printf("            border-right: #111 solid 1px; font-size: 14px; line-height: 16px; }\n");
      printf("  .view::-webkit-scrollbar { background: #fc3; width: 10px; }\n");
      printf("  .view::-webkit-scrollbar-thumb { background: #fff; border-radius: 6px;\n");
      printf("            border: #555 inset 1px; }\n");
      printf("  .viewT { background-color: #eee; font-size: 14px; max-width: 75%; overflow: auto; }\n");
      printf("  .viewA { background-color: #177; font-size: 10px; max-width: 75%;\n");
      printf("           overflow: scroll; color: #0ee; font-family: Verdana; word-wrap: break-word; }\n");
      printf("  .viewC { background-color: #000; font-size: 12px; max-width: 75%;\n");
      printf("           overflow: scroll; color: #ee0; font-family: 'Courier New', monospace; }\n");
      printf("  .viewM { background-color: #555; font-size: 14px; max-width: 75%; }\n");
      printf("  .viewU { background-color: #333; font-size: 14px; max-width: 75%; }\n");
      printf("  .viewI { background-color: #111; font-size: 14px; max-width: 75%; }\n");
      printf("  #nextdir { display: none; position: absolute; bottom: 30px; left: 60%; right: 0; height: 14px;");
      printf("             background-color: #bbb; opacity: 0.6; border-radius: 8px; }\n"); // invisible iframes
      printf("  #nextdir > iframe { border: #000 solid 1px; border-radius: 3px; width: 12px; height: 12px; }\n");
      printf("  #status { position: absolute; bottom: 0; left: 0; right: 0; text-align: right;\n");
      printf("            display: none; font-size: 14px; line-height: 14px; }\n"); // hidden status ....
      printf("  div.detail { font-size: 14px; line-height: 14px; font-face: monospace; }\n");
      printf("  b.R { color: #e00; } b.DR { color: #800; }\n");
      printf("  b.Y { color: #ee0; } b.DY { color: #880; }\n");
      printf("  b.G { color: #0e0; } b.DG { color: #080; }\n");
      printf("  b.C { color: #0ee; } b.DC { color: #088; }\n");
      printf("  b.B { color: #00e; } b.DB { color: #008; }\n");
      printf("  b.M { color: #e0e; } b.DM { color: #808; }\n");
      printf("  b.K { color: #111; } b.W  { color: #eee; }\n");
      printf("  b.D { color: #666; } b.L  { color: #aaa; }\n");
      printf("  b.folder { background-color: #77e; color: #fff; width: 100%; height: 16px;\n");
      printf("             display: block; float: left; padding: 0 12px; overflow: hidden; }\n");
      printf("  b.filename { background-color: #fc3; color: #1b1; width: 100%; height: 16px;\n");
      printf("               display: block; float: left; padding: 0 12px; overflow: hidden; }\n");
      printf("  b.filelink { font-weight: normal; color: #11e; }\n");
      printf("  b.filelink:hover { font-weight: normal; cursor: pointer; color: #39d; }\n");
      printf("  b.dlfilelinksel { font-weight: normal; font-style: italic; color: #b2b; }\n");
      printf("  b.dlfilelinksel:hover { font-weight: normal; cursor: pointer; color: #d1d; }\n");
      printf("  b.dlfilelink { font-weight: normal; font-style: italic; color: #888; }\n");
      printf("  b.dlfilelink:hover { font-weight: normal; font-style: italic; cursor: pointer; color: #d1d; }\n");
      printf("  b.lbl { font-variant: small-caps; font-size: 12px; width: 75px; padding-right: 4px;\n");
      printf("           text-align: right; display: block; float: left; clear: none; }\n");
      printf("  b.perm { font-weight: normal; }\n");
      printf("  b.match { font-variant: small-caps; }\n");
      printf("</style>\n");
}

VD framehtmlincludescript() {
      printf("<script>\n");
      printf("  function id(id) { return document.getElementById(id); }\n");
      printf("  function selectthis(item, seltype) {\n");
      printf("    var selected = 0;\n");
      printf("    var reselected = 0;\n");
      printf("    var cleared = 0;\n");
      printf("    var list = item.parentElement;\n");
      printf("    while (list.id.charAt(0) != 'l') {\n"); // look for l0, l1, l2 etc in case of sub-button
      printf("      if (list.className != 'detail') { item = list; }\n"); // retain item of detail
      printf("      list = list.parentElement;\n"); // traverse to parent until list is found
      printf("    }\n");
      printf("    while (list) {\n");
      printf("      var it = list.firstElementChild;\n");
      printf("      while (it) {\n");
      printf("        if (it == item) {\n"); // should only match in first list
      printf("          if (it.className == 'file')            { it.className = seltype; selected++; }\n");
      printf("          else if (it.className == 'filesel')    { reselected++; }\n");
      printf("          else if (it.className == 'dlfilesel')  { reselected++; }\n"); // _ remember file was dl'ed
      printf("          else if (it.className == 'dlfile')     { it.className = 'dlfilesel'; selected++; }\n");
      printf("          else if (it.className == 'filelink')   { it.className = 'dlfilelinksel'; selected++; }\n");
      printf("          else if (it.className == 'dlfilelink') { it.className = 'dlfilelinksel'; selected++; }\n");
      printf("          else if (it.className == 'link')       { it.className = seltype; selected++; }\n");
      printf("          else if (it.className == 'linksel')    { reselected++; }\n");
      printf("          else if (it.className == 'subdir')     { it.className = seltype; selected++; }\n");
      printf("          else if (it.className == 'subdirsel' || it.className == 'subdirdeetsel') {\n");
      printf("            if (it.className == seltype)         { reselected++; }\n");
      printf("            else { it.className = seltype; selected++; }\n");
      printf("          } else if (it.className == 'special')  { it.className = seltype; selected++; }\n");
      printf("          else if (it.className == 'specialsel' && it.className ) { reselected++; }\n");
      printf("        } else { \n");
      printf("          if (seltype != 'dlfile' && seltype != 'viewfile') {\n"); // don't deselect parent if download/view is clicked
      printf("            if (it.className == 'filesel')            { it.className = 'file';       cleared++; }\n");
//      printf("            else if (it.className == 'filelinksel')   { it.className = 'filelink';   cleared++; }\n");
// ^ add when allowing multiple selections - build zip link below, select files, click download zip
      printf("            else if (it.className == 'dlfilelinksel') { it.className = 'dlfilelink'; cleared++; }\n");
      printf("            else if (it.className == 'linksel')       { it.className = 'link';       cleared++; }\n");
      printf("            else if (it.className == 'subdirsel')     { it.className = 'subdir';     cleared++; }\n");
      printf("            else if (it.className == 'subdirdeetsel') { it.className = 'subdir';     cleared++; }\n");
      printf("            else if (it.className == 'specialsel')    { it.className = 'special';    cleared++; }\n");
      printf("          } else {\n"); // deselect dlfilelinksel on list click too ^ data will probably be replaced anyway
      printf("            if (it.className == 'dlfilelinksel') { it.className = 'dlfilelink'; cleared++; }\n");
      printf("          }\n");
      printf("        }\n"); // the child of the selecting list will presumably be replaced
      printf("        it = it.nextElementSibling;\n");
      printf("        if (it && it.className == 'detail')\n");  // if this is a detail div
      printf("          { it = it.firstElementChild; }\n");     //  traverse its elements
      printf("      }\n");
      printf("      list = list.previousElementSibling;\n");
      printf("    }\n");
      printf("    return { cleared: cleared, selected: selected, reselected: reselected };\n");
      printf("  }\n");
      printf("  function subdir(item, dirname) {\n");
      printf("    selectthis(item, 'subdirsel');\n");
      printf("    id('subdir').src = '/io/R:?' + dirname + '/';\n");
      printf("  }\n");
      printf("  function subdeets(item, dirname) {\n");
      printf("    selectthis(item, 'subdirdeetsel');\n");
      printf("    id('subdir').src = '/io/R:?' + dirname + '/.';\n");
      printf("  }\n");
      printf("  function subfile(item, filename) {\n");
      printf("    selectthis(item, 'filesel');\n");
      printf("    id('subdir').src = '/io/R:?' + filename;\n");
      printf("  }\n");
      printf("  function sublink(item, linkname) {\n");
      printf("    selectthis(item, 'linksel');\n");
      printf("    id('subdir').src = '/io/R:?' + linkname;\n");
      printf("  }\n");
      printf("  function subspecial(item, specialname) {\n");
      printf("    selectthis(item, 'specialsel');\n");
      printf("    id('subdir').src = '/io/R:?' + specialname;\n");
      printf("  }\n");
// Download, Zip, Code, dAta, Text, aUdio, Video, ...........
      printf("  function download(item, filepath) {\n");
      printf("    selectthis(item, 'dlfile');\n"); // or rather, downloadthis(item) for progress bar
      printf("    console.log('The file should download after a warning:');\n");
      printf("    id('download').src = '/io/R:?:D:' + filepath;\n");
      printf("    console.log('For some reason, .o files (and maybe other unrecognised types) fail');\n");
      printf("  }\n");
// todo: downloadzip and buildzip

      printf("  function view(type, item, filepath, offset) {\n");
      printf("    if (item) { selectthis(item, 'viewfile'); }\n"); // e.g. NULL for todo in same window
      printf("    console.log('The ' + type + ' file will try to open...');\n");
      printf("    var actionchar = 'T';\n"); // text by default --- info/histogram by default instead?
      printf("    if      (type == 'text' ) { actionchar = 'T'; }\n");
      printf("    else if (type == 'data' ) { actionchar = 'A'; }\n");
      printf("    else if (type == 'code' ) { actionchar = 'C'; }\n");
      printf("    else if (type == 'image') { actionchar = 'M'; }\n");
      printf("    else if (type == 'audio') { actionchar = 'U'; }\n");
      printf("    else if (type == 'video') { actionchar = 'I'; }\n");
//      printf("    else if (type == '?'    ) { actionchar = 'V'; }\n"); // view via fileinfo
      printf("    if (offset > 0) {\n");
      printf("      var filepathoffset = '/';\n");
      printf("      while (offset > 0)\n");
      printf("        { filepathoffset += './'; offset--; }\n");
      printf("      var filepathsplit = filepath.split('/');\n");
      printf("      var filename = filepathsplit.pop();\n");
      printf("      filepath = filepathsplit.join('/') + filepathoffset + filename;\n");
      printf("    }\n");
      printf("    id('download').src = '/io/R:?:' + actionchar + ':' + filepath;\n");
      printf("  }\n");
      printf("  function subfilethenview(item, filepath) {\n");
//      printf("    view('?', item, filepath);\n");
      printf("    selectthis(item, 'filesel');\n"); // fileviewsel maybe
      printf("    id('subdir').src = '/io/R:?:V:' + filepath;\n"); // todo:view mode
      printf("  }\n");
      printf("  function checkdl() {\n");
      printf("    if (!id('download').contentWindow) { console.log('no dl document!!'); return; }\n");
      printf("    var content = id('download').contentWindow.document;\n");
      printf("    var bodytext = content.body.innerHTML;\n");
      printf("    var errortext = content.getElementById('error');\n");
      printf("    if (errortext) { errortext = errortext.innerHTML; }\n");
      printf("    else { errortext = bodytext.substr(0, 30); }\n"); // only look for error within the first 30 chars
      printf("    if (bodytext == '') {\n"); // no error id but blank body = major error (unless init)
      printf("      console.log('blank dl content');\n"); // normal for init but should change to differentiate server error
      printf("    } else if (errortext.indexOf('fail: ') > -1) {\n");
      printf("      id('status').innerHTML = 'Fail: <b class=\"DR\">' + errortext + '</b>';\n");
      printf("    } else if (errortext.indexOf(' error: ') > -1) {\n");
      printf("      id('status').innerHTML = 'Error: <b class=\"DR\">' + errortext + '</b>';\n");
      printf("    } else if (content.getElementById('view')) {\n");
      printf("      var dirs = content.title.split('/');\n");
      printf("      var thisfilename = '';\n"); // != '' if this is a file
      printf("      if (dirs[0] == '' && dirs.length > 1) {\n");
      printf("        if (dirs[dirs.length - 1] != '') {\n"); // this is a file
//      printf("          if (dirs[dirs.length - 1] != '.')\n"); // this is not dirinfo
//      printf("            { thisfilename = dirs[dirs.length - 1]; dirs.push(''); }\n");
//      printf("          else { dirs[dirs.length - 1] = ''; }\n");
// ^ do not expect dirinfo in the case of view - at this time - may be useful for playlists ... incl /.mp3
      printf("          thisfilename = dirs[dirs.length - 1];\n");
      printf("          var tree = id('tree');\n");
//      printf("          var viewoffset = 2;\n"); // (+1 child of fileinfo: optional), +1 child of subdir
      printf("          var viewoffset = 1;\n"); // for more, extra ./s will be added to path
      printf("          var level = dirs.length - 3 + viewoffset;\n"); // - 2 for first and last blank (""/"N:"/"")
// ^ could also source level from where it was clicked - might be important if dirinfo trees could view files
// ^ checkdl() would need to recover the item parameter, presumably from a global fifo - also prevent clicks
//    while fifo has a pending item to prevent skipped downloads (the list updates regardless - no confirmation!!)
      printf("          var contentdiv = content.getElementById('view');\n");
//      printf("          var contentdata = content.body.innerHTML;\n");
//      printf("          if (contentdiv)\n"); // should be true
      printf("          var contentstyle = 'view ' + contentdiv.className;\n");
      printf("          var contentdata = contentdiv.innerHTML;\n");
      printf("          if (id('l' + level)) {\n"); // replace existing view - todo: consider side-by-side views
      printf("            var div = id('l' + level);\n");
      printf("            div.className = contentstyle;\n");
      printf("            div.innerHTML = contentdata;\n");
      printf("            while (id('l' + (++level)))\n");
      printf("              { tree.removeChild(id('l' + level)); }\n");
      printf("            var rightedge = div.offsetLeft + div.offsetWidth;\n");
      printf("            var scrollright = tree.offsetLeft + tree.scrollLeft;\n");
      printf("            if (rightedge > scrollright)\n");
      printf("              { tree.scrollLeft = rightedge - tree.offsetWidth; }\n");
      printf("          } else if (level > 0 && !id('l' + (level - 1))) {\n"); 
      printf("            console.log('tree level ' + level + ' error (-1 not found)');\n");
      printf("          } else {\n");
      printf("            var div = document.createElement('div');\n");
      printf("            div.id = 'l' + level;\n");
      printf("            div.className = contentstyle;\n");
      printf("            div.innerHTML = contentdata;\n");
      printf("            tree.appendChild(div);\n");
      printf("            var rightedge = div.offsetLeft + div.offsetWidth;\n");
      printf("            var scrollright = tree.offsetLeft + tree.scrollLeft;\n");
      printf("            if (rightedge > scrollright)\n");
      printf("              { tree.scrollLeft = rightedge - tree.offsetWidth; }\n");
      printf("          }\n");
      printf("          content.body.innerHTML = '';"); // clear iframe to prevent media duplication
      printf("        }\n");
      printf("      }\n");
      printf("    } else {\n");
//      printf("      var folder = content.getElementById('folder');\n");
//      printf("      var name = content.getElementById('name');\n");
// downloaded as attachment... can we also send html code with it?
// downloads do not seem to trigger checkdl() ......................................
//      printf("      if
// OR nothing else above matched and no download actually occurred! 
      printf("      id('status').innerHTML = '<b class=\"DG\">Downloaded...(?)</b>';\n");
      printf("    }\n");
      printf("  }\n");
      printf("  function errordl() {\n");
      printf("    console.log('errordl');\n");
      printf("  }\n");
      printf("  function abortdl() {\n");
      printf("    console.log('abortdl');\n");
      printf("  }\n");
      printf("  function loaddir() {\n");
      printf("    var content = id('subdir').contentWindow;\n");
      printf("    var pagedata = content.document;\n");
      printf("    var pagetitle = pagedata.title;\n");
      printf("    var bodytext = pagedata.body.innerHTML;\n");
      printf("    var errortext = pagedata.getElementById('error');\n");
      printf("    if (errortext) { errortext = errortext.innerHTML; }\n");
      printf("    else { errortext = bodytext.substr(0, 30); }\n"); // only look for error within the first 30 chars
      printf("    if (bodytext == '') {\n"); // no error id but blank body = major error (unless init)
      printf("      console.log('blank dir content');\n"); // normal for init but should change to differentiate server error
      printf("    } else if (errortext.indexOf('fail: ') > -1) {\n");
      printf("      id('status').innerHTML = 'Error: <b class=\"DR\">' + errortext + '</b>';\n");
      printf("    } else if (pagedata.getElementById('lnew')) {\n"); // expect data in lnew
//      printf("    if (errortext.indexOf('fail: ') > -1) {\n");
 //     printf("      id('status').innerHTML = '<b class=\"DR\">' + errortext + '</b>';\n");
 //     printf("      console.log('loaddir: ' + errortext);\n");
 //     printf("      return;\n");
      printf("      var todo = pagedata.getElementById('todo');\n");
      printf("      if (todo) {\n");
      printf("        var toclick = todo.onclick.toString();\n");
      printf("        toclick = toclick.substr(toclick.indexOf('{'));\n");
      printf("        toclick = toclick.substr(0, toclick.lastIndexOf('}'));\n");
      printf("        var totype = toclick.substr(toclick.indexOf('view(\"') + 6);\n");
      printf("        totype = totype.substr(0, totype.indexOf('\"'));\n");
      printf("        var topath = toclick.substr(toclick.lastIndexOf(', \"') + 3);\n");
      printf("        topath = topath.substr(0, topath.indexOf('\"'));\n"); // consider quotes in filenames!! TODO
      printf("        todo.id = '';\n"); // don't carry todo to main interface
      printf("        view(totype, todo, topath);\n"); // need to remove a /./ ?---------------------!@#$%^&*(
      printf("      }\n");
      printf("      var dirs = pagedata.title.split('/');\n");
      printf("      var thisfilename = '';\n"); // != '' if this is a file
      printf("      if (dirs[0] == '' && dirs.length > 1) {\n");
      printf("        if (dirs[dirs.length - 1] != '') {\n"); // this is a file
      printf("          if (dirs[dirs.length - 1] != '.')\n"); // this is not dirinfo
      printf("            { thisfilename = dirs[dirs.length - 1]; dirs.push(''); }\n");
      printf("          else { dirs[dirs.length - 1] = ''; }\n");
      printf("        }\n");
      printf("        if (dirs[dirs.length - 1] == '') {\n"); // this is a dir or fileinfo
      printf("          var tree = id('tree');\n");
      printf("          var level = dirs.length - 3;\n"); // - 2 for first and last blank (""/"N:"/"")
      printf("          var contentdiv = pagedata.getElementById('lnew');\n");
      printf("          var contentdata = pagedata.body.innerHTML;\n");
      printf("          if (contentdiv)\n");
      printf("            { contentdata = contentdiv.innerHTML; }\n");
      printf("          if (id('l' + level)) {\n");
      printf("            var div = id('l' + level);\n");
      printf("            div.className = 'dir';\n");
      printf("            div.innerHTML = contentdata;\n");
      printf("            while (id('l' + (++level)))\n");
      printf("              { tree.removeChild(id('l' + level)); }\n");
      printf("            var rightedge = div.offsetLeft + div.offsetWidth;\n");
      printf("            var scrollright = tree.offsetLeft + tree.scrollLeft;\n");
      printf("            if (rightedge > scrollright)\n");
      printf("              { tree.scrollLeft = rightedge - tree.offsetWidth; }\n");
      printf("          } else if (level > 0 && !id('l' + (level - 1))) {\n"); 
      printf("            console.log('tree level ' + level + ' error (- 1 not found)');\n");
      printf("          } else {\n");
      printf("            var div = document.createElement('div');\n");
      printf("            div.id = 'l' + level;\n");
      printf("            div.className = 'dir';\n");
      printf("            div.innerHTML = contentdata;\n");
      printf("            tree.appendChild(div);\n");
      printf("            var rightedge = div.offsetLeft + div.offsetWidth;\n");
      printf("            var scrollright = tree.offsetLeft + tree.scrollLeft;\n");
      printf("            if (rightedge > scrollright)\n");
      printf("              { tree.scrollLeft = rightedge - tree.offsetWidth; }\n");
      printf("          }\n");
      printf("        } else {\n");
      printf("          console.log('not a dir or a file .. wut .....');\n");
      printf("        }\n");
      printf("      }\n");
      printf("      id('status').innerHTML = '';\n"); // erase old checkdl status
      printf("    }\n"); // end of lnew match
      printf("  }\n");
      printf("</script>\n");
}

#define DRIVELEN    32    // allows up to ~36*28 drive names eg '/102343654235443253455279532A:/'
#define QUERYLEN    2048
#define PATHLEN     2048
#define MAXLEVELS   512
// prefix query with :D: to download a file
// :Z: to download as a zip file


VD showfiletree(CS dirpath, IN dirlevel, IN lastlist) {
  struct dirent **namelist;
  IN numfiles = scandir(dirpath, &namelist, 0, alphasort);
//  IF (dirlevel EQ 0 AND numfiles EQ 3) {
//    lastentry = 1; // detect if this is actually the last entry ... not relevant for 0!
  IF (numfiles LT 0) {
    printf("showfiletreefail: %s", dirpath);
  } EL {
    IN i = -1;
    WI (INC i LT numfiles) {
      CS name = namelist[i]->d_name;
      IF (namelist[i]->d_type EQ DT_DIR) {
        IF (name[0] EQ '.' AND name[1] EQNUL) {
          IF (numfiles NQ 2) { CT; } // show . in empty directories
        } EF (name[0] EQ '.' AND name[1] EQ '.' AND name[2] EQNUL)
          { CT; }
      }
      IF (dirlevel GQ 0) { // all have a prefix
        IN dli = -1;
        WI (INC dli LT dirlevel) {
          IF (((lastlist >> dli) & 1) EQ 0)
           { U1(Uboxud); } EL { U1(Uboxlozenge); } // change to Uboxgap
        }
        IF (i EQ numfiles - 1 OR numfiles EQ 2) { // last entry
//          IF (namelist[i]->d_type EQ DT_DIR)      // ..is a dir
//            { U1(Uboxudr); } // all dirs have something
//          EL { U1(Uboxur); } // prefix for . if numfiles EQ 2
          U1(Uboxur);
        } EL { U1(Uboxudr); } // not last entry
//        IN dli = 0;
//        WI (INC dli LQ dirlevel)
//          { U1(Uboxlr); }
      }
      IF (namelist[i]->d_type EQ DT_REG) {
//        printf(" <b class='filelink' onclick='download(this, \"%s/%s\");'>", querystr, name);
        printf(" <b class='filelink' onclick='download(this, \"%s/%s\");'>", dirpath, name);
        printf("%s", name); // add * if exectutable ?
        printf("</b><br />\n");
      } EF (namelist[i]->d_type EQ DT_LNK) {
        printf(" <i>%s</i>@<br />\n", name);
      } EF (namelist[i]->d_type EQ DT_DIR) {
        IF (name[0] EQ '.' AND name[1] EQNUL) {
          printf(" <i>%s</i><br />\n", " (empty)"); // .
        } EL {
          printf(" <b>%s</b>/<br />\n", name);
          CH subdirpath[PATHLEN];
          sprintf(subdirpath, "%s/%s", dirpath, name);
          IF (i EQ numfiles - 1)
            { lastlist |= (1 << dirlevel); } // last in this column
          showfiletree(subdirpath, dirlevel + 1, lastlist);
        }
      } EL { // special file e.g. pipe
        printf(" %s|", name);
      }
      free(namelist[i]);
    }
    free(namelist);
  }
}

IN Rdrive($) {
  CS gateway = getenv("GATEWAY_INTERFACE");
  CS querystr = getenv("QUERY_STRING");
  IF (!gateway AND $N GT 0) {
  //  printf("TODO: CONSOLE MODE\n");
    querystr = $1;
  } EF (!querystr) {
    printf("NO QUERY\n");
    RT 0;
  }
  CS oldquery = querystr;
  // consider conversion of %chars
  CH drive[DRIVELEN];
  sprintf(drive, "%s", Rfolder);
  CH dirpath[QUERYLEN];
  CH action = NUL; // action = Download, Zip .... + Build ?
  CH includescript = 0;
  CH includedrivelist = 0;
  IF (querystr AND (querystr[0] NQNUL)) {
    IF (querystr[0] EQ ':' AND querystr[2] EQ ':')
      { action = querystr[1]; querystr = &querystr[3]; }
//    IF (querystr[0] EQ '/') {
    IN dmi = 1; // could also start at 2 if / precedes drivename (1 is ok tho)
    WI (querystr[dmi] NQ ':' AND querystr[dmi] NQNUL) {
      IF (querystr[dmi] EQ '/') { BK; } //dmi = -1; BK; }
      INC dmi;
    }
    IF (querystr[dmi] EQ ':' AND querystr[dmi + 1] EQ '/') {
      // drives end in : ... ignore pathnames that include : (invalid anyway)
      IF (querystr[0] EQ '/')          // eat the preceding slash delimiter
        { querystr = &querystr[1]; DEC dmi; }   // nom
      querystr[dmi + 1] = NUL;         // NUL the proceeding slash delimiter
      sprintf(drive, "/%s/", querystr); // add path delim back
      querystr = &querystr[dmi + 2];   // process remainder of path
      sprintf(dirpath, "%s%s", drive, querystr);
    } EL {
      sprintf(dirpath, "%s%s", Rfolder, querystr);
    }
  } EL {
    sprintf(dirpath, "%s", Rfolder);
    querystr = ""; // NULL; // root query - returns drive list  ... ""; // as in ./
    includescript = 1;
    includedrivelist = 1;
    // isadir = 1;
  }
  CH isadir = 0;
  CH isdirinfo = 0;
//  IF (!querystr OR (oldquery AND oldquery[0] EQNUL)) { // any path, incl drive change = subframe content
//    includescript = 1; // this will load the scripts and drive list
//    includedrivelist = 1; // 
  IF (querystr[0] EQNUL) { // no path
//  } EF (querystr[0] EQNUL) {
    isadir = 1;
//    includescript = 1; // l0 (now called lnew) is loaded dynamically from drive list
  } EL {     // else resolve path
    CS dirp = dirpath;
    WI (dirp[0] NQNUL) { INC dirp; }
    DEC dirp;
    IF (dirp[0] EQ '/') { isadir = 1; }
    EF (*(dirp - 1) EQ '/' AND dirp[0] EQ '.') { isdirinfo = 1; }
  }
  // if (isadir && action) { offer dir in a zip? or :Z: :D:
  IF (isadir) {
    framehtmlheader();
// TODO: STOP LOADING SUB-IFRAMES FOR SUBDIRECTORIES - one set at a time tho, no big deal
    printf("<html><head>\n<title>%s</title>\n", dirpath);
// IF ...loaded in iframe .... no need: ........ how to tell tho
    IF (includescript) {
      framehtmlincludestyle();
      framehtmlincludescript();
    }
    printf("</head><body>\n");
    struct dirent **namelist;
    IN numfiles = scandir(dirpath, &namelist, 0, alphasort);
    IF (numfiles LT 0) {
      printf("scandirfail %s", dirpath);
    } EL {
      printf("<div class='tree' id='tree'>\n");
      IF (includedrivelist) { // include drive list in main interface
// location is "." rather than querystr+name
// because this program is called R: .... /S:/ needs to redirect to S drive
        CS drives[] = RDRIVELIST;
        printf("<div class='dir' id='ld'>\n");
        printf(  "<b class='folder'>Drives</b><br />\n");
        IN driveix = 0;
        WI (drives[driveix] NQNULL) {
          CS drive = drives[driveix];
          printf(  "<div class='subdir' onclick='subdir(this, \"%s\");'>", drive);
          printf(    "<div class='suffix'>"); //<b>./</b>");
          printf(      "<u onclick='subdeets(this, \"%s\"); event.stopPropagation();'>&#8882;</u>", drive);
          printf(    "</div>");
          printf(    "<b>%s</b>", drive);
          printf(  "</div>\n");
          INC driveix;
        }
        printf("</div>\n");
      } EL {     // else if a path is given, load that path in lnew (somehow generate relative interface? :R:?)
        printf("<div class='dir' id='lnew'>\n");
        printf("<b class='folder'>(%d) %s</b><br />\n", numfiles, dirpath);
        IN pass = 1; // 4 passes - special, folders, links, files
        WI (pass LQ 4) {
          IN i = -1;
          WI (INC i LT numfiles) {
            CS name = namelist[i]->d_name;
            UCH type = namelist[i]->d_type;
            IF (pass EQ 4 AND type EQ DT_REG) {
              printf("<div class='file' onclick='subfile(this, \"%s%s\");'", querystr, name);
              printf(" ondblclick='subfilethenview(this, \"%s%s\");'>", querystr, name);
// load file info - save download() for download button
//          printf("<div class='file' onclick='download(\"%s%s\");'>", querystr, name);
// check if executable
//        printf("<div class='suffix'>/</div>");
              printf("%s", name);
              printf("</div>\n");
            } EF (pass EQ 3 AND type EQ DT_LNK) {
              printf("<div class='link'>");
              printf("<div class='suffix'>@</div>");
              printf("<i>%s</i>", name);
              printf("</div>\n");
            } EF (pass EQ 2 AND type EQ DT_DIR) {
              IF (name[0] EQ '.' AND name[1] EQNUL) { CT; }
              IF (name[0] EQ '.' AND name[1] EQ '.' AND name[2] EQNUL) { CT; }
              printf("<div class='subdir' onclick='subdir(this, \"%s%s\");'>", querystr, name);
              printf("<div class='suffix'>"); //<b>./</b>");
              printf("<u onclick='subdeets(this, \"%s%s\"); event.stopPropagation();'>&#8882;</u>", querystr, name);
              printf("</div>");
              printf("<b>%s/</b>", name);
              printf("</div>\n");
            } EF (pass EQ 1 AND ANDNQ3(type, DT_REG, DT_LNK, DT_DIR)) { // and type is special or anything else
              printf("<div class='special'>");
              printf("<div class='suffix'>|</div>");
              printf("%s", name);
              printf("</div>\n");
            }
            IF (pass EQ 4) // free on last pass
              { free(namelist[i]); }
          }
          INC pass; // stops after 4 passes
        }
        free(namelist);
        printf("</div>\n"); // end of lnew (nee l0)
      }
      printf("</div>\n"); // end of tree
      if (includescript) {
        printf("<div id='nextdir'>\n");
        printf("  <div id='status'></div>\n");
        printf("  <iframe id='subdir' src='' onload='loaddir();'></iframe>\n");
        printf("  <iframe id='download' src='' onload='checkdl();' onerror='errordl();' onabort='abortdl();'></iframe>\n");
        printf("</div>\n");
      }
    }
    printf("</body></html>\n");
  } EL { // this is a file - display info or download?
    IF (action EQ 'D') {
      FS dlfile = OPENFILE(dirpath);
      IF (!dlfile) {
        frametextheader();
        printf("openfilefail: %s", dirpath);
      } EL {
        CS fname = dirpath;
        CH hasslash = 0;
        WI (fname[0] NQNUL) {
          IF (fname[0] EQ '/')
            { hasslash = 1; }
          INC fname;
        }
        IF (!hasslash) { // shouldn't happen ..
          frametextheader();
          printf("seeknamefail: %s", dirpath);
        } EL {
          WI (fname[0] NQ '/')
            { DEC fname; }
          fname[0] = '\0';
          // this is a file... or a link to a file.... or something else notadir/
          framedownloadheader(INC fname);
          WI (1) {
            IN inch = GETFCH(dlfile);
            BKEQEOF(inch);
            PUTSTDCH(inch);
          }
        }
      }
  // } EF (action EQ 'Z') { // zip
    } EFEQ3(action, 'T', 'A', 'C') { // [View = load info first], Text, dAta, Code
      framehtmlheader();
      printf("<html><head>\n<title>%s</title>\n</head><body>\n", dirpath);
      printf("<div class='view%c'id='view'>\n", action);
//      printf(  "<b id='name' class='filename'>%s</b><br />\n", dirpath);
      FS file = OPENFILE(dirpath);
      IF (!file) {
        printf("<b id='error' class='DR'>Unable to open file.</b><br />\n");
      } EL {
        CH isbinary = 0; // looks for control codes excluding \t \n \r
//        CH isutf8 = 0; // detect utf8 later
        IN lastinch = NUL;
        IN inch = NUL;
        INWI1(ix, -1) {
          inch = GETFCH(file);
          BKEQEOF(inch);
          IF (inch LT ' ' AND inch NQ '\t' AND inch NQ '\n' AND inch NQ '\r')
            { isbinary = 1; BK; }
          EF (inch EQ 127) { isbinary = 1; BK; }
//        EF (inch GQ 128)  { isutf8 = 1; BK; } support utf8 blindly
          EF (inch EQ '\n') { printf("<br />\n"); }
          EF (inch EQ '\r') { printf(""); } // ignore \r at this time
          EF (inch EQ '\t') { printf("&nbsp;&nbsp;&nbsp;&nbsp;"); }
          EF (inch EQ '<' ) { printf("&lt;");     }
          EF (inch EQ '>' ) { printf("&gt;");     }
          EF (inch EQ '"' ) { printf("&quot;");   }
          EF (inch EQ '\'') { printf("&apos;");   }
          EF (inch EQ ' ' AND lastinch EQ ' ')  { printf("&nbsp;");   }
          EL { PUTSTDCH(inch); }
          lastinch = inch;
        }
        IF (isbinary)
          { printf("<b class='R'>Binary char %d detected.</b>", inch); }
        CLOSEFILE(file);
      }
    // the actions 'U', 'I' and 'M' are resolved later as they require MIME type info
//    } EFEQ(action, 'O') { // Open ...
// return file with signature ... see dat
    } EL { // display file info -- unless type is 'O', then return the content after type detection!
      CH todoview = 0;
      CH openthis = 0;
      CH openviewer = 0;
      IF (action EQ 'O') {
        openthis = 1;
      } EFEQ3(action, 'U', 'I', 'M') {
        openviewer = 1; // delay until MIMES resolved
      } EL {
        framehtmlheader();
        printf("<html><head>\n<title>%s</title>\n</head><body>\n", dirpath);
        printf("<div class='file' id='lnew'>\n");
        IF (action EQ 'V') { // here to determine the view method
          todoview = 1;
        } EF (action NQNUL) // here because action failed
          { printf("<b id='error' class='DR'>Cannot -[%c]-</b><br />\n", action); }
        IF (isdirinfo) {
          printf("<b id='folder' class='folder'>%s</b><br />\n", dirpath);
          printf("<div class='detail'>");
          showfiletree(dirpath, 0, 0); // note the benign /. suffix
          printf("</div>\n");
        } EL {
          printf("<b id='name' class='filename'>%s</b><br />\n", dirpath);
        }
      }
// location field would probably split dirpath.. split font later
// check signature
      FS file = OPENFILE(dirpath);
      IF (!file) {
        IF (openthis) { frametextheader(); printf("Unable to open file.\n"); }
        EL { printf("<b id='error' class='DR'>Unable to open file.</b><br />\n"); }
      } EL {
        CH isbinary = 0; // looks for control codes excluding \t \n \r
        CH sig[32]; // warning: tiny files may match a random signature (mem not cleared)
        IN siglen = 32; // certain files need to check further
        INWI1(ix, -1) {
          IN inch = GETFCH(file);
          BKEQEOF(inch);
          IF (INC ix LT siglen)
            { sig[ix] = inch; }
          IF (inch LT 32 AND inch NQ '\t' AND inch NQ '\n' AND inch NQ '\r')
            { isbinary = 1; }
        }
        CLOSEFILE(file);
        // PERMISSION ----------------------------------------------------------------------
        IN filebytesize = -1;
        IN filekbsize = -1;
        IN fileowneruid = -1;
        IN fileownergid = -1;
        CH fileperm[UGERDWREX]; // has len 12
        sprintf(fileperm, "%s %s %s", "???", "???", "???"); // assumes len 12
        struct stat st;
        IF (stat(dirpath, &st) EQ 0) {
          fileowneruid = st.st_uid;
          fileownergid = st.st_gid;
          filebytesize = st.st_size;
          filekbsize = filebytesize / 1024;
  // st.st_dev = ID of device containing file
  // st.st_ino = inode number of file
  // st.st_rdev = device ID for special file
// http://man7.org/linux/man-pages/man2/fstat.2.html
// http://man7.org/linux/man-pages/man7/inode.7.html
          mode_t perm = st.st_mode;
          fileperm[URD] = (perm & S_IRUSR) ? 'r' : '-';
          fileperm[UWR] = (perm & S_IWUSR) ? 'w' : '-';
          fileperm[UEX] = (perm & S_IXUSR) ? 'x' : '-';
          fileperm[UGEGAP1] = ' ';
          fileperm[GRD] = (perm & S_IRGRP) ? 'r' : '-';
          fileperm[GWR] = (perm & S_IWGRP) ? 'w' : '-';
          fileperm[GEX] = (perm & S_IXGRP) ? 'x' : '-';
          fileperm[UGEGAP2] = ' ';
          fileperm[ERD] = (perm & S_IROTH) ? 'r' : '-';
          fileperm[EWR] = (perm & S_IWOTH) ? 'w' : '-';
          fileperm[EEX] = (perm & S_IXOTH) ? 'x' : '-';
          fileperm[UGEEND] = NUL;
        } // display later .. todo: use colours ... format is rrr www xxx
        // EXTENSION ----------------------------------------------------------------------
        CH filehasext = 0;
        CH filehaspath = 0;
        CH filepathhasslashes = 0; // escaped / as in \/ .. not allowed on some systems
        CS filepathroot = dirpath; // should become empty if nothing before first /
        TAG filepathtags; // malloc space for ix 1,2,etc
        filepathtags.index = -1; // empty
        TAG *lastpathtag = NULL;
        TAG *thispathtag = NULL; // path tags incl/ filename
        CS filetitle = dirpath; // will change after each path delimiter / ... was NULL
        CH filetitlehastags = 0; // more than just title.ext eg title.tag1.tag2.ext
        CH filetitlehasdots = 0; // for example blarg v1.2.3a.x86.exe has dots, and x86 as a tag
        TAG filenametags;
        filenametags.index = -1; // empty
        TAG *lastnametag = NULL;
        TAG *thisnametag = NULL; // name tags incl/ ext
        CH filenamehasslashes = 1;
        CH tagisnum = 0;
        CS filenameext = "";
        CH dirpathcopy[QUERYLEN];
        sprintf(dirpathcopy, "%s", dirpath); // copy path before split
        CS fileext = dirpath; // if no ., ext will end up NUL
        WI (fileext[0] NQNUL) {
          IF (fileext[0] EQ '.') { // a . delimits title/tags/ext
// can predict if this is a /path.ext/ by looking ahead for a subsequent /
// pathtaghasext = 1; EL .. no need, check filepathtags for .s
// titlehasdots if this is indeed a file extension (or it was a tag) and tagisnum
// taghasdots would be checked for each tag
// filetitlehastags if filehasext was already true... filehasext stays true unless fileext[1] EQNUL
            IF (filehasext EQ 1) // this is not the first .
              { filetitlehastags = 1; filehasext = 0; } // becomes 1 again
            IF (fileext[1] NQNUL AND fileext[1] NQ '.')
              { filehasext = 1; } // hasext if not empty t.a..g or ext.
            tagisnum = ISNUMBER(fileext[1]) ? 1 : 0; // tag is num if first digit is
            IF (tagisnum) { // file-1.2.3.exe will not consider 2 and 3 to be tags
              filetitlehasdots = 1; // bla v1.2.3   ... bl.a v1.2.3 will see "a v1" as a tag
              filetitlehastags = 0; // all prior tags become part of title
              IF (thisnametag->index GT -1) { // if tags have already been found ... undo them
                TAG *undotag = &filenametags;
                *(undotag->tag - 1) = '.'; // restore the . before the first tag
                WI (undotag->next NQNULL) {
                  undotag = undotag->next;
                  *(undotag->tag - 1) = '.'; // restore the . before the next tag
                  free(undotag); // free memory for all tags except first
                }
                filenametags.index = -1; // set tag list as empty
              } // no more tags... but if this is ext as in 3gp it should be added as the final tag.....
              filehasext = 0; // ext will be later... but consider extensions starting with numbers!!!
              // filehasext = 1 if no more dots.. extensions that are recognised should be noticed.. or not?
              // eg 3gp is an extension but 3a would be a version number ... suggest mgp instead?
              // if a number tag is found, all tags before it are part of the title....
              // need to undo the existing tag list and rebuild the title...................
            } EL { // else tag is tag or ext (which is the last tag) (including if blank. )
         //   IF (filetitle EQNULL) { // first . delimits title // IF it's DIRPATH it's not set-----------------
            // set file title earlier, at each / delimiter
              IF (filenametags.index EQ -1) { // first tag - note that list can be reset
                fileext[0] = NUL; // delimit end of title (dirpath or last path component)
//                filetitle = thispathtag->tag; // it's the final path tag // already set
                thisnametag = &filenametags; // first tag = static tag
                thisnametag->tag = &fileext[1]; // first name tag, including ext
                thisnametag->index = 0; // tag 0 is not the title! 0 is ext if no tags
                thisnametag->next = NULL; // a file ending in . will add one blank tag, filehasext == 0
              } EL { // dots after delimit tag.tag.tag.ext
                fileext[0] = NUL; // delimit end of tag
                thisnametag->next = (TAG *)malloc(sizeof(TAG)); // remember to free() !
                lastnametag = thisnametag;
                thisnametag = lastnametag->next;
                thisnametag->tag = &fileext[1]; // next tag starts after .
                thisnametag->index = (lastnametag->index + 1);
                thisnametag->next = NULL;
              }
            } // this . either added a tag or, if numeric, merged the list into the title
          } EF (fileext[0] EQ '/') { // a / delimits a path component
            IF (fileext GT dirpath AND (*(fileext - 1) EQ '\\')) {
              filenamehasslashes = 1; // or pathname has slashes
            } EL { // this / is a path delimiter
              IF (filenamehasslashes) // prior \/ was in path, not filename
                { filepathhasslashes = 1; filenamehasslashes = 0; }
   //           IF (filehaspath EQ 0) { // first path tag
              IF (filepathtags.index EQ -1) { // first path tag
                fileext[0] = NUL; // delimit previous tag - first tag appears after first / (e.g. R:)
                filehaspath = 1; // pathless filenames with slashes will have filehaspath == 0
 //               filepathroot = dirpath; // will be empty if dirpath starts with /
                thispathtag = &filepathtags; // first tag = static tag
                thispathtag->tag = &fileext[1]; // R: , no \0 yet
                thispathtag->index = 0;
                thispathtag->next = NULL;
                filetitle = thispathtag->tag; // next tag is title until next delim clarifies
              } EL { // next path tag
                fileext[0] = NUL; // delimit previous tag - next tag starts after next /
                thispathtag->next = (TAG *)malloc(sizeof(TAG)); // remember to free() !
                lastpathtag = thispathtag;
                thispathtag = lastpathtag->next;
                thispathtag->tag = &fileext[1]; // next tag starts after /
                thispathtag->index = (lastpathtag->index + 1);
                thispathtag->next = NULL;
                filetitle = thispathtag->tag; // next tag is title until next delim clarifies
              } // if filehaspath EQ 0 and hasext = 1, first path component = title
              filehasext = 0;  // escaped slashes in extensions technically allowed
              // ^ path tags/extensions ignored by this flag reset at / delim, use filepathtags
              tagisnum = 0; // not looking for numeric tags in path components or title
            }
          }
          INC fileext;
        }
        IF (filehasext) {
          IF (filenametags.index GT -1) {
            fileext = thisnametag->tag; // latest name tag
          } EL { fileext = "(missing)"; } // this shouldn't happen
        }
        IF (!openthis AND !openviewer) {
          IF (filepathroot) { // e.g. hostname in hostname/R:/dir/file.txt
            printf("<b class='lbl'>Path Root:</b> ");
            IF (filepathroot[0] EQNUL) {
              printf("<i>(local)</i><br />\n");
            } EL {
              printf("%s<br />\n", filepathroot);
            }
          }
          IF (filepathtags.index GT -1) {
            printf("<b class='lbl'>Path Tags:</b> ");
            IF (filepathtags.tag EQ filetitle) {
              printf("<i>(title only)</i><br />\n");
            } EL {
              TAG *pathtag = &filepathtags;
              IF (pathtag->tag NQ filetitle) {
                printf("%s", pathtag->tag);
              } EL { printf("<i>(title)</i>"); }
              WI (pathtag->next NQNULL) {
                pathtag = pathtag->next;
                IF (pathtag->tag NQ filetitle) {
                   printf(", %s", pathtag->tag);
                } EL { printf(", <i>(title)</i>"); }
                free(pathtag); // free memory for all tags except first
              }
              printf("<br />\n");
              filepathtags.index = -1; // tag list is now empty
            }
          } // list should always have one entry - title
          IF (filetitle) { // should be true
            printf("<b class='lbl'>File Title: </b>");
            IF (filetitle[0] EQNUL) {
              printf("<i>(none)</i><br />\n");
            } EL {
              printf("<u>%s</u><br />\n", filetitle);
            }
          }
          IF (filenametags.index GT -1) {
            printf("<b class='lbl'>Name Tags:</b> ");
            IF (filenametags.tag EQ fileext) {
              printf("<i>(ext only)</i><br />\n");
            } EL {
              TAG *nametag = &filenametags;
              IF (nametag->tag NQ fileext) {
                printf("%s", nametag->tag);
              } EL { printf("<i>(ext)</i>"); }
              WI (nametag->next NQNULL) {
                nametag = nametag->next;
                IF (nametag->tag NQ fileext) {
                  printf(", %s", nametag->tag);
                } EL { printf(", <i>(ext)</i>"); }
                free(nametag); // free memory for all tags except first
              }
              printf("<br />\n");
              filenametags.index = -1; // tag list is now empty
            }
          } // list should always have one entry - extension
          printf("<b class='lbl'>Extension:</b> ");
          IF (filehasext) {
            printf("%s<br />\n", fileext);
          } EL {
            printf("(none)<br />\n");
          }
 // no more tags... but if this is ext as in 3gp it should be added as the final tag.....
          printf("<b class='lbl'>Permission:</b> ");
          printf("<b class='perm'>%s</b><br />\n", fileperm);

          printf("<b class='lbl'>File Size:</b> ");
          IF (filekbsize GT 0) {
            printf("%d KB<br />\n", filekbsize);
          } EL {
            printf("%d bytes<br />\n", filebytesize);
          }
 //         printf("Title: ");
 //         CS filetitle = fileext;
          printf("<b class='lbl'>Signature:</b> ");
        } // end of blocking fileinfo display for 'O' action
        // file extensions containing plaintext - nonbinaries
        // need not check for a signature in most cases
        CS sigexe        = "EXE (Windows Binary)";
        CS sigelf        = "ELF (Linux Binary)";
        CS sigzip        = "ZIP (zip-like Compression)";
        CS sigzipempty   = "ZIP (Empty Archive)";
        CS sigzipspanned = "ZIP (Spanned Archive)";
        CS sigrar        = "RAR (rar Compressed)";
        CS sigbz2        = "BZ2 (bzip2 Compressed)";
        CS sigiso        = "ISO (Archive, CD Image)";
        CS sigtar        = "TAR (Tape Archive)";
        CS sig7zip       = "7ZIP (7z Compressed)";
        CS siggzip       = "GZIP (gz Compressed)";
        CS sigxz         = "XZ (lzma2 Compressed)";
        CS sigzliblow    = "ZLIB (zip/deflate Compressed, Low)";
        CS sigzlibdef    = "ZLIB (zip/deflate Compressed, Default)";
        CS sigzlibbest   = "ZLIB (zip/deflate Compressed, Best)";
        CS sigico        = "ICO (Icon)";
        CS sigjpg        = "JPG (JFIF Encoded)";
        CS sigpng        = "PNG (ZLIB Compressed)";
        CS sigbmp        = "BMP (Raster Bitmap)";
        CS siggif87      = "GIF (GIF87 Compressed)";
        CS siggif89      = "GIF (GIF89 Compressed)";
        CS sigaiff       = "AIFF (PCM Audio Interchange)";
        CS sigogg        = "OGG (OGA/OGV Vorbis Media)";
        CS sigmp3v1      = "MP3 (MPEG Audio, ID3v1)";
        CS sigmp3v2      = "MP3 (MPEG Audio, ID3v2)";
        CS sigflac       = "FLAC (Lossless Audio)";
        CS sigmidi       = "MIDI (Digital Audio)";
        CS sigwav        = "WAV (Waveform Audio)";
        CS sigavi        = "AVI (Audio Video Interleave)";
        CS sigasf        = "ASF (WMA/WMV Media)";
        CS sig3gp        = "3GP (Multimedia File)";
        CS sigswf        = "SWF (ShockWave Flash)";
        CS sigflv        = "FLV (Flash Video File)";
        CS sigwebm       = "WEBM (MKV/A/S/3D Media)";
        CS sigmpg        = "MPG (MPEG Media)";
        CS sigmp4        = "MP4 (MPEG-4 Media)";
        CS sigmp4iso     = "MP4 (ISO Base MPEG-4 Media)"; // perhaps not playable ?
        CS sigps         = "PS (PostScript Document)";
        CS sigpdf        = "PDF (Portable Document)";
        CS sigdoc        = "DOC (DOC/XLS/PPT/MSG Document)";
        CS sigxml        = "XML (Extensible Markup)";
        CS sigrtf        = "RTF (Rich Text Document)";
        CS signotexpected = "Not Expected";
        CS signotrecognised = "Not Recognised";
        CS sigundetected = "Undetected"; // the standard action for text files
        CS filesig       = sigundetected;
        CS sig4 = &sig[4];
        CS sig6 = &sig[6];
        CS sig8 = &sig[8];
        // Program format signatures -----------------------------------
        IF VEQ2(sig, 0x4D, 0x5A)             { filesig = sigexe; }
        EF VEQ4(sig, 0x7F, 0x45, 0x4C, 0x46) { filesig = sigelf; }
        // Archive/compression signatures ------------------------------
        EF VEQ4(sig, 0x50, 0x4B, 0x03, 0x04) {
          filesig = sigzip; // could be jar, odt etc
        } EF VEQ4(sig, 0x50, 0x4B, 0x05, 0x06) { filesig = sigzipempty;   }
        EF VEQ4(sig, 0x50, 0x4B, 0x07, 0x08)   { filesig = sigzipspanned; }
        EF VEQ4(sig, 0x52, 0x61, 0x72, 0x21)   { filesig = sigrar; }
        EF VEQ3(sig, 0x42, 0x5A, 0x68)         { filesig = sigbz2; }
        EF VEQ5(sig, 0x43, 0x44, 0x30, 0x30, 0x31) { // maybe at sig[0x8001,0x8801,0x9001]
          filesig = sigiso;
        } EF VEQ5(sig, 0x75, 0x73, 0x74, 0x61, 0x72) { // at 0x101
          filesig = sigtar;
        } EF VEQ6(sig, 0x37, 0x7A, 0xBC, 0xAF, 0x27, 0x1C) { filesig = sig7zip; }
        EF VEQ2(sig, 0x1F, 0x8B)                           { filesig = siggzip; }
        EF VEQ5(sig, 0xFD, 0x37, 0x7A, 0x58, 0x5A) { filesig = sigxz; }
        EF VEQ2(sig, 0x78, 0x01)                   { filesig = sigzliblow;  }
        EF VEQ2(sig, 0x78, 0x9C)                   { filesig = sigzlibdef;  }
        EF VEQ2(sig, 0x78, 0xDA)                   { filesig = sigzlibbest; }
        // Image/picture signatures ------------------------------------
        EF VEQ4(sig, 0x00, 0x00, 0x01, 0x00) { filesig = sigico; }
        EF VEQ3(sig, 0xFF, 0xD8, 0xFF)       { filesig = sigjpg; }
        EF VEQ4(sig, 0x89, 0x50, 0x4E, 0x47) { filesig = sigpng; }
        EF VEQ2(sig, 0x42, 0x4D)             { filesig = sigbmp; }
        EF VEQ6(sig, 0x47, 0x49, 0x46, 0x38, 0x37, 0x61) { filesig = siggif87; }
        EF VEQ6(sig, 0x47, 0x49, 0x46, 0x38, 0x39, 0x61) { filesig = siggif89; }
        // Audio/sound signatures --------------------------------------
        EF VEQ4(sig, 0x46, 0x4F, 0x52, 0x4D) { // MODE....
          IF VEQ4(sig8, 0x41, 0x49, 0x46, 0x46) {
            filesig = sigaiff;
          } // EF fantavision movie etc
        } EF VEQ4(sig, 0x4F, 0x67, 0x67, 0x53) { filesig = sigogg; }
        EF VEQ2(sig, 0xFF, 0xFB)             { filesig = sigmp3v1; }
        EF VEQ3(sig, 0x49, 0x44, 0x33)       { filesig = sigmp3v2; }
        EF VEQ4(sig, 0x66, 0x4C, 0x61, 0x43) { filesig = sigflac;  }
        EF VEQ4(sig, 0x4D, 0x54, 0x68, 0x64) { filesig = sigmidi;  }
        EF VEQ4(sig, 0x52, 0x49, 0x46, 0x46) { // RIFF....
          IF VEQ4(sig8, 0x57, 0x41, 0x56, 0x45) { filesig = sigwav; }
        // Video/multimedia signatures ---------------------------------
          EF VEQ4(sig8, 0x41, 0x56, 0x49, 0x20) { filesig = sigavi; }
        } EF VEQ6(sig, 0x30, 0x26, 0xB2, 0x75, 0x8E, 0x66) { filesig = sigasf; }
// + 4 byte offset?
        EF VEQ6(sig4, 0x66, 0x74, 0x79, 0x70, 0x33, 0x67)  { filesig = sig3gp; }
        EF (VEQ3(sig, 0x43, 0x57, 0x53) OR
            VEQ3(sig, 0x46, 0x57, 0x53)   )  { filesig = sigswf; }
        EF VEQ3(sig, 0x46, 0x4C, 0x56)       { filesig = sigflv; }
        EF VEQ4(sig, 0x1A, 0x45, 0xDF, 0xA3) { filesig = sigwebm; }
        EF (VEQ4(sig, 0x00, 0x00, 0x01, 0xBA) OR // DVD/Program or MPEG type
            VEQ4(sig, 0x00, 0x00, 0x01, 0xB3)   ) { filesig = sigmpg;  }
        EF VEQ6(sig6, 0x79, 0x70, 0x4D, 0x53, 0x4E, 0x56) { filesig = sigmp4; }
        EF VEQ6(sig6, 0x79, 0x70, 0x69, 0x73, 0x6F, 0x6D) { filesig = sigmp4iso; }
        // Document signatures -----------------------------------------
        EF VEQ4(sig, 0x25, 0x21, 0x50, 0x53)       { filesig = sigps;  }
        EF VEQ5(sig, 0x25, 0x50, 0x44, 0x46, 0x2D) { filesig = sigpdf; }
        EF VEQ5(sig, 0xD0, 0xCF, 0x11, 0xE0, 0xA1) { filesig = sigdoc; }
        EF VEQ6(sig, 0x3C, 0x3F, 0x78, 0x6D, 0x6C, 0x20) { filesig = sigxml; }
        EF VEQ6(sig, 0x7B, 0x5C, 0x72, 0x74, 0x66, 0x31) { filesig = sigrtf; }
        // Note that most text files have no header signature....
//        EL { filesig = signotrecognised; } // leave as undetected until text can be verified
        IF (!openthis AND !openviewer) {
          printf("%s<br />\n", filesig);
          // FILE TYPE (requires read permission for binary type detection) ----------------------
          printf("<b class='lbl'>Is Binary:</b> ");
          printf("%s<br />\n", (isbinary) ? "Yes" : "No");
          printf("<b class='lbl'>File Type:</b> ");
        } // more fileinfo display blocking for 'O'
        CS filetype = "Unknown";
        CS filetypetype = filetype;
        CS typeprogram = "Program";
        CS typeexe     =  ".exe"; // (x86) ... // x64 ..?
        CS typeelf     =  ".bin/.elf"; // x86 or arm6 or arm7
        CS typearchive = "Archive";
        CS typezip     =  ".zip";
        CS typerar     =  ".rar";
        CS typebz2     =  ".bz2";
        CS typeiso     =  ".iso";
        CS typetar     =  ".tar";
        CS type7z      =  ".7z";
        CS typegz      =  ".gz";
        CS typexz      =  ".xz";
        CS typezlib    =  ".zlib";
        CS typeimage = "Image";
        CS typeico   =  ".ico";
        CS typejpg   =  ".jpg/.jpeg";
        CS typepng   =  ".png";
        CS typebmp   =  ".bmp";
        CS typegif   =  ".gif";
        CS typeaudio = "Audio";
        CS typeaiff  =  ".aif/.aiff";
        CS typemp3   =  ".mp3";
        CS typeflac  =  ".fla/.flac";
        CS typemidi  =  ".mid/.midi";
        CS typewav   =  ".wav/.wave";
        CS typeoga   =  ".ogg/.oga";
        CS typewma   =  ".asf/.wma";
        CS typeweba  =  ".mka/.webm";
        CS typevideo = "Video";
        CS typeogv   =  ".ogg/.ogv";
        CS typewmv   =  ".asf/.wmv";
        CS typeavi   =  ".avi";
        CS type3gp   =  ".3gp";
        CS typeswf   =  ".swf";
        CS typeflv   =  ".flv";
        CS typewebm  =  ".mkv/.webm";
        CS typempeg  =  ".mpg/.mpeg";
        CS typemp4   =  ".mp4/.mpeg4";
        CS typedocument = "Document";
        CS typeps       = ".ps";
        CS typepdf      = ".pdf";
        CS typedoc      = ".doc/.xls/.ppt/.msg";
        CS typexml      = ".xml";
        CS typertf      = ".rtf";
        CS typetext = "Text";
        CS typetxt  =  ".txt";
        CS typecode = "Code";
        CS typevjs  =  ".vjs";
        CS typevec  =  ".vec";
        CS typelvl  =  ".lvl";
        CS typeh    =  ".h";
        CS typec    =  ".c";
        CS typecpp  =  ".cpp";
        CS typescript = "Script";
        CS typegcc    =  ".gcc";
        CS typesh     =  ".sh";
        CH sigmatchestype = 0;
        CS viewnone = "none";
        CS viewtext = "text";
        CS viewdata = "data";
        CS viewcode = "code";
        CS viewimage = "image";
        CS viewaudio = "audio";
        CS viewvideo = "video";
        CS viewtype = viewnone;
        IF (filehasext) {
          // Program signature checks
          IF STREQCI(fileext, "exe") {
            IF (filesig EQ sigexe) { sigmatchestype = 1; }
            filetype = typeexe; filetypetype = typeprogram;
          } EF STREQANY2CI(fileext, "elf", "bin") {
            IF (filesig EQ sigelf) { sigmatchestype = 1; }
            filetype = typeelf; filetypetype = typeprogram;
          // Archive signature checks
          } EF STREQCI(fileext, "zip") {
            IF EQANY3(filesig, sigzip, sigzipempty, sigzipspanned) { sigmatchestype = 1; }
            filetype = typezip; filetypetype = typearchive;
          } EF STREQCI(fileext, "rar") {
            IF (filesig EQ sigrar) { sigmatchestype = 1; }
            filetype = typerar; filetypetype = typearchive;
          } EF STREQCI(fileext, "bz2") {
            IF (filesig EQ sigbz2) { sigmatchestype = 1; }
            filetype = typebz2; filetypetype = typearchive;
          } EF STREQCI(fileext, "iso") {
            IF (filesig EQ sigiso) { sigmatchestype = 1; }
            filetype = typeiso; filetypetype = typearchive;
          } EF STREQCI(fileext, "tar") {
            IF (filesig EQ sigtar) { sigmatchestype = 1; }
            filetype = typetar; filetypetype = typearchive;
          } EF STREQCI(fileext, "7z") {
            IF (filesig EQ sig7zip) { sigmatchestype = 1; }
            filetype = type7z; filetypetype = typearchive;
          } EF STREQCI(fileext, "gz") {
            IF (filesig EQ siggzip) { sigmatchestype = 1; }
            filetype = typegz; filetypetype = typearchive;
          } EF STREQCI(fileext, "xz") {
            IF (filesig EQ sigxz) { sigmatchestype = 1; }
            filetype = typexz; filetypetype = typearchive;
          } EF STREQCI(fileext, "zlib") {
            IF EQANY3(filesig, sigzliblow, sigzlibdef, sigzlibbest) { sigmatchestype = 1; }
            filetype = typezlib; filetypetype = typearchive;
          // Image signature checks
          } EF STREQCI(fileext, "ico") {
            IF (filesig EQ sigico) { sigmatchestype = 1; }
            filetype = typeico; filetypetype = typeimage;
            // convert to enable viewing
          } EF STREQANY2CI(fileext, "jpg", "jpeg") {
            IF (filesig EQ sigjpg) { sigmatchestype = 1; }
            filetype = typejpg; filetypetype = typeimage;
            viewtype = viewimage;
          } EF STREQCI(fileext, "png") {
            IF (filesig EQ sigpng) { sigmatchestype = 1; }
            filetype = typepng; filetypetype = typeimage;
            viewtype = viewimage;
          } EF STREQCI(fileext, "bmp") {
            IF (filesig EQ sigbmp) { sigmatchestype = 1; }
            filetype = typebmp; filetypetype = typeimage;
            // convert before viewing or view?
          } EF STREQCI(fileext, "gif") {
            IF EQANY2(filesig, siggif87, siggif89) { sigmatchestype = 1; }
            filetype = typegif; filetypetype = typeimage;
            viewtype = viewimage;
          // Audio signature checks
          } EF STREQANY2CI(fileext, "aif", "aiff") {
            IF (filesig EQ sigaiff) { sigmatchestype = 1; }
            filetype = typeaiff; filetypetype = typeaudio;
          } EF STREQCI(fileext, "mp3") {
            IF EQANY2(filesig, sigmp3v1, sigmp3v2) { sigmatchestype = 1; }
            filetype = typemp3; filetypetype = typeaudio;
            viewtype = viewaudio;
          } EF STREQANY2CI(fileext, "fla", "flac") {
            IF (filesig EQ sigflac) { sigmatchestype = 1; }
            filetype = typeflac; filetypetype = typeaudio;
            viewtype = viewaudio;
          } EF STREQANY2CI(fileext, "mid", "midi") {
            IF (filesig EQ sigmidi) { sigmatchestype = 1; }
            filetype = typemidi; filetypetype = typeaudio;
            viewtype = viewaudio;
          } EF STREQANY2CI(fileext, "wav", "wave") {
            IF (filesig EQ sigwav) { sigmatchestype = 1; }
            filetype = typewav; filetypetype = typeaudio;
            viewtype = viewaudio;
          // Audio/video/multimedia signature checks
          } EF STREQANY2CI(fileext, "ogg", "oga") {
            IF (filesig EQ sigogg) { sigmatchestype = 1; }
            filetype = typeoga; filetypetype = typeaudio; // unless ogg + has video
            viewtype = viewaudio;
          } EF STREQCI(fileext, "ogv") {
            IF (filesig EQ sigogg) { sigmatchestype = 1; }
            filetype = typeogv; filetypetype = typevideo;
          } EF STREQANY2CI(fileext, "asf", "wma") {
            IF (filesig EQ sigasf) { sigmatchestype = 1; }
            filetype = typewma; filetypetype = typeaudio; // unless asf + has video
          } EF STREQCI(fileext, "wmv") {
            IF (filesig EQ sigasf) { sigmatchestype = 1; }
            filetype = typewmv; filetypetype = typevideo;
          } EF STREQCI(fileext, "mka") { // webm could also contain just audio
            IF (filesig EQ sigwebm) { sigmatchestype = 1; }
            filetype = typeweba; filetypetype = typeaudio;
          // Video/multimedia signature checks
          } EF STREQCI(fileext, "avi") {
            IF (filesig EQ sigavi) { sigmatchestype = 1; }
            filetype = typeavi; filetypetype = typevideo;
            // cannot view or depends on compression algorithm?
          } EF STREQANY4CI(fileext, "3gp", "3g2", "3gpp", "3gpp2") {
            IF (filesig EQ sig3gp) { sigmatchestype = 1; }
            filetype = type3gp; filetypetype = typevideo;
            viewtype = viewvideo;
          } EF STREQCI(fileext, "swf") {
            IF (filesig EQ sigflv) { // consider flv wrapped as swf
              sigmatchestype = 1; // actually, it doesn't! but allow it to play
              filetype = typeflv; filetypetype = typevideo;
              viewtype = viewvideo; // may need a special plugin
            } EL {
              IF (filesig EQ sigswf) { sigmatchestype = 1; }
              filetype = typeswf; filetypetype = typevideo;
              viewtype = viewvideo; // may need a special container
            }
          } EF STREQCI(fileext, "flv") {
            IF (filesig EQ sigswf) { sigmatchestype = 1; }
            filetype = typeswf; filetypetype = typevideo;
            viewtype = viewvideo; // may need a special container
          } EF STREQANY4CI(fileext, "mkv", "mks", "mk3d", "webm") {
            IF (filesig EQ sigwebm) { sigmatchestype = 1; }
            filetype = typewebm; filetypetype = typevideo;
            viewtype = viewvideo; // todo: warn about high bandwidth video............
          } EF STREQANY3CI(fileext, "mpg", "mpeg", "vob") { // could contain just audio ...
            IF (filesig EQ sigmpg) { sigmatchestype = 1; } // VOB = DVD type -- same mime as MPG?
            filetype = typempeg; filetypetype = typevideo;
            viewtype = viewvideo;
          } EF STREQANY2CI(fileext, "mp4", "mpeg4") { // there could be more than one signature type .....
            IF (filesig EQ sigmp4iso) {
              sigmatchestype = 1; // assume normal mp4 type for now......
              filetype = typemp4; filetypetype = typevideo;
              viewtype = viewvideo;
            } EL {
              IF (filesig EQ sigmp4) { sigmatchestype = 1; }
              filetype = typemp4; filetypetype = typevideo;
              viewtype = viewvideo;
            }
          // Document/markup signature checks
          } EF STREQCI(fileext, "ps") {
            IF (filesig EQ sigps) { sigmatchestype = 1; }
            filetype = typeps; filetypetype = typedocument;
          } EF STREQCI(fileext, "pdf") {
            IF (filesig EQ sigpdf) { sigmatchestype = 1; }
            filetype = typepdf; filetypetype = typedocument;
          } EF STREQANY4CI(fileext, "doc", "xls", "ppt", "msg") {
            IF (filesig EQ sigdoc) { sigmatchestype = 1; }
            filetype = typedoc; filetypetype = typedocument;
          } EF STREQCI(fileext, "xml") {
            IF (filesig EQ sigxml) { sigmatchestype = 1; }
            filetype = typexml; filetypetype = typedocument;
          } EF STREQCI(fileext, "rtf") {
            IF (filesig EQ sigrtf) { sigmatchestype = 1; }
            filetype = typertf; filetypetype = typedocument;
          // Text signature checks
          } EF STREQCI(fileext, "txt") {
            filetype = typetxt; filetypetype = typetext;
            viewtype = viewtext;
          // Code signature checks
          } EF STREQCI(fileext, "vjs") {
            filetype = typevjs; filetypetype = typecode;
            viewtype = viewdata;
          } EF STREQCI(fileext, "vec") {
            filetype = typevec; filetypetype = typecode;
            viewtype = viewdata;
          } EF STREQCI(fileext, "lvl") {
            filetype = typelvl; filetypetype = typecode;
            viewtype = viewdata;
          } EF STREQCI(fileext, "h") {
            filetype = typeh;   filetypetype = typecode;
            viewtype = viewcode;
          } EF STREQCI(fileext, "c") {
            filetype = typec;   filetypetype = typecode;
            viewtype = viewcode;
          } EF STREQCI(fileext, "cpp") {
            filetype = typecpp; filetypetype = typecode;
            viewtype = viewcode;
          // Script signature checks
          } EF STREQCI(fileext, "gcc") {
            filetype = typegcc; filetypetype = typescript;
            viewtype = viewcode;
          } EF STREQCI(fileext, "sh") {
            filetype = typesh;  filetypetype = typescript;
            viewtype = viewcode;
          } // can also find scripts by looking for #! interpreter or #comment
        } EL { // programs with no extension could be binary or script
          IF (filesig EQ sigelf) {
            sigmatchestype = 1; // program with no extension
            filetype = typeelf; filetypetype = typeprogram;
          } EF (fileperm[2] EQ 'x' AND !isbinary) { // executable by user
            sigmatchestype = 1; // script with no extension
            // confirm with interpreter ? #!/cmd/sh .. soon!
          // } EF () { special name with no extension
          }
        }
        CS mimetypeinvalid = "invalid";
        CS mimetypejpg  = "image/jpeg";
        CS mimetypegif  = "image/gif";
        CS mimetypepng  = "image/png";
        CS mimetypemp3  = "audio/mpeg"; // chrome: "audio/mp3"
        CS mimetypewav  = "audio/wave"; // chrome: "audio/wav", also "x-wav" and "x-pn-wav"
        CS mimetypeflac = "audio/flac"; // also "audio/x-flac"
        CS mimetypeoga  = "audio/ogg";  // also "application/ogg" if unknown if audio/video
        CS mimetypemp4  = "video/mp4";  // may only support standard format
        CS mimetypewebm = "video/webm"; // could also be audio-only ... detect later
        CS mimetypeogv  = "video/ogg";  // also "application/ogg" if unknown content
        CS mimetype = mimetypeinvalid;
        // be sure to set viewtype = view... to enable the "as Type" link
        IF (filetype EQ typejpg)  { mimetype = mimetypejpg;  }
        EF (filetype EQ typegif)  { mimetype = mimetypegif;  }
        EF (filetype EQ typepng)  { mimetype = mimetypepng;  }
        EF (filetype EQ typemp3)  { mimetype = mimetypemp3;  }
        EF (filetype EQ typewav)  { mimetype = mimetypewav;  }
        EF (filetype EQ typeflac) { mimetype = mimetypeflac; }
        EF (filetype EQ typeoga)  { mimetype = mimetypeoga;  }
        EF (filetype EQ typemp4)  { mimetype = mimetypemp4;  }
        EF (filetype EQ typewebm) { mimetype = mimetypewebm; }
        EF (filetype EQ typeogv)  { mimetype = mimetypeogv;  }








        IF (!openthis AND !openviewer) {
          printf("%s (%s)<br />\n", filetypetype, filetype);
          IF (sigmatchestype) {
            printf("<b class='match'>Signature Matches Extension</b><br />\n");
          }
          printf("<br />\n");
          IF (viewtype NQ viewnone) {
            printf("<b class='lbl'>View:</b> as ");          
            CS viewtag = "b";
            IF (todoview) { viewtag = "b id='todo'"; }
            printf("<%s class='filelink' onclick='view(\"%s\", this, \"%s\", 1);'>", viewtag, viewtype, dirpathcopy);
            printf("%s", viewtype);
            printf("</b><br />\n");
          }
          printf("<b class='lbl'>Download:</b> ");          
          printf("<b class='filelink' onclick='download(this, \"%s\");'>", dirpathcopy);
          CS filename = dirpathcopy + (filetitle - dirpath); // name + tags + ext
          printf("%s", filename); // filename); // add * if exectutable ?
          printf("</b><br />\n");
        } EF (openviewer) { // finally... MIME types mean time to write
          framehtmlheader();
          printf("<html><head>\n<title>%s</title>\n</head><body>\n", dirpathcopy);
          printf("<div class='view%c'id='view'>\n", action);
          IFEQ(action, 'U') { // aUdio viewer
            CS size     = " style='margin: 45% 20px 0 20px; width: 250px; height: 28px;'";
            CS autoplay = " autoplay";
            CS autoloop = ""; // " loop";
            printf("<audio controls%s%s%s>\n", size, autoplay, autoloop);
            printf(  "<source src='/io/R:?:O:%s' type='%s' />", dirpathcopy, mimetype); 
            printf("This browser does not support the audio tag.</audio>");
// consider preferences for autoplay=false in .det file (file, dir, drive, user preference)
          } EFEQ(action, 'I') { // vIdeo viewer
            CS margin   = " style='margin: 30% 20px 0 20px;'"; // later ask the video for its size!
            CS autoplay = " autoplay";
            CS autoloop = ""; // " loop";
            printf("<video width='400' height='300' controls%s%s%s>\n", margin, autoplay, autoloop);
            printf(  "<source src='/io/R:?:O:%s' type='%s' />", dirpathcopy, mimetype); 
            printf("This browser does not support the video tag.</video>");
          } EFEQ(action, 'M') { // iMage viewer
            CS limitsize = " style='margin: 5% 0 0 2px; max-width: 100%; max-height: 90%;'";
            printf("<img%s src='/io/R:?:O:%s' />\n", limitsize, dirpathcopy);
          } EL {
            printf("No viewer available for this file type.");
          }
        } EL { // open this ...............................
          IF (filesig NQ sigundetected AND !sigmatchestype) {
            frametextheader();
            printf("Signature/Type mismatch: %s vs %s.\n", filesig, filetype);
          } EF (mimetype EQ mimetypeinvalid) {
            frametextheader();
            printf("Unsupported MIME type.\n");
          } EL {
            FS datafile = OPENFILE(dirpathcopy);
            IF (!datafile) {
              frametextheader(); printf("Datafile reopen fail.\n");
            } EL {
              CS range = getenv("HTTP_RANGE");
              IF (!range) { // no range = open whole file
                IN rangelen = framefulldataheader(mimetype, filebytesize);
                IN rindex = -1;
                WI (INC rindex LT rangelen) {
                  IN inch = GETFCH(datafile);
                  IF (inch EQEOF) {
                    printf("\n!!EOF!!\n");
                    BK; // file ended early!
                  } EL { STDPUTCH(inch); }
                } // write data bytes
                CLOSEFILE(datafile);
                RT 0; // return success for full file transfer
              } EF STRPREFIXEQ(range, "bytes=") {
                CS rangevalch = &range[6];
                IN rstart = 0;
                IN rstop = -1;
                CH rstat = '[';
                WI (rangevalch[0] NQNUL) {
                  IF ISNUMCHAR(rangevalch[0]) {
                    IF (rstat EQ '[')
                      { rstart = (rstart * 10) + (rangevalch[0] - A0); }
                    EF (rstat EQ '-')
                      { rstop = 0 + (rangevalch[0] - A0);        rstat = ']'; }
                    EF (rstat EQ ']')
                      { rstop = (rstop * 10) + (rangevalch[0] - A0);   }
                  } EF (rangevalch[0] EQ '-' AND rstat EQ '[') { rstat = '-'; }
                  EL { rstart = -1; BK; }
                  INC rangevalch;
                }
                IF (rstart LT 0 OR rstop LT rstart) { // includes if rstop < 0 by logic
                  frametextheader(); printf("Invalid range numbers.\n");
                } EL {
                  IN rangelen = framepartdataheader(mimetype, rstart, rstop, filebytesize);
                  IN rindex = -1;
                  WI (INC rindex LT rangelen) {
                    IN inch = GETFCH(datafile);
                    IF (inch EQEOF) {
                      printf("\n!!EOF!!\n");
                      BK; // file ended early!
                    } EL { STDPUTCH(inch); }
                  } // write data bytes
                } // close file on range error, and on success
                CLOSEFILE(datafile);
                RT 206; // return success for partial file transfer
              } EL { frametextheader(); printf("Invalid range request.\n"); }
            } // file was open - writing data range ends here
          } // end of when sig matches type (-> write data)
        } // end of file open procedure
      } // end of file handling (open then reopen if necessary)
      IF (!openthis) { // valid 'O' actions will return.. invalid may end up here
        printf("</div>\n"); // all html views need to close (openviewer et al)!
        printf("</body></html>\n"); // all html needs to </html>
      } // no footer for openfile errors (or filedata, which returns 0 or 206)
    }
  }
  RT 0;
}
