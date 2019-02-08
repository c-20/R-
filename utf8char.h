#define MAXUTF8CHARLEN     32

#define Uboxtl    0x250C
#define Uboxdr    Uboxtl   // down-right at top-left
//#define Uboxudl   0x251C
#define Uboxtbl   0x251C
#define Uboxudr   Uboxtbl  // up-down-right at middle-left
#define Uboxtbr   0x2524
#define Uboxudl   Uboxtbr  // up-down-left at middle-right
#define Uboxtr    0x2510
#define Uboxdl    Uboxtr   // down-left at top-right
#define Uboxbl    0x2514
#define Uboxur    Uboxbl   // up-right at bottom-left
#define Uboxbr    0x2518
#define Uboxul    Uboxbr   // up-left at bottom-right
#define Uboxhz    0x2500
#define Uboxlr    Uboxhz   // left-right is horizontal
#define Uboxvt    0x2502
#define Uboxud    Uboxvt   // up-down is vertical
#define Uboxudlr  0x253C   // up-down-left-right
#define Uboxdiamond  0x25C7
#define Uboxtinysquare   0x25AB
#define Uboxlozenge      0x25CA
// still need middle-top and middle-bottom

UCS nextutf8char(UCS str, INP codepoint) {
  IN seqlen;
  IN datalen = (IN)strlen((CCS)str);
  UCS p = str;
  IF (datalen LT 1 OR str[0] EQNUL)
    { RT NULL; }
  IF (!(str[0] & 0x80)) {
    *codepoint = (wchar_t)str[0];
    seqlen = 1;
  } EF ((str[0] & 0xE0) == 0xC0) {
    *codepoint = (IN)(((str[0] & 0x1F) << 6) | (str[1] & 0x3F));
    seqlen = 2;
  } EF ((str[0] & 0xF0) == 0xE0) {
    *codepoint = (IN)(((str[0] & 0x0F) << 12) | ((str[1] & 0x3F) << 6) | (str[2] & 0x3F));
    seqlen = 3;
  } EL { RT NULL; }
  p += seqlen;
  RT p;
}

IN utf8thischar(IN codepoint, UCS utf8buffer) {
  IF INRANGE(codepoint, 0, 127) {
    // 0xxxxxxx
    utf8buffer[0] = codepoint;
    utf8buffer[1] = NUL;
    RT 1;
  } EF INRANGE(codepoint, 128, 2047) {
    // 110xxxxx 10xxxxxx
    utf8buffer[0] = (codepoint >> 6) + 0xC0;
    utf8buffer[1] = (codepoint & 0x3F) + 0x80;
    utf8buffer[2] = NUL;
    RT 2;
  } EF INRANGE(codepoint, 2048, 65535) {
    // 1110xxxx 10xxxxxx 10xxxxxx
    utf8buffer[0] = (codepoint >> 12) + 0xE0;
    utf8buffer[1] = ((codepoint >> 6) & 0x3F) + 0x80;
    utf8buffer[2] = (codepoint & 0x3F) + 0x80;
    utf8buffer[3] = NUL;
    RT 3;
  } EF INRANGE(codepoint, 65536, 1112064) {
    // 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    utf8buffer[0] = (codepoint >> 18) + 0xF0;
    utf8buffer[1] = ((codepoint >> 12) & 0x3F) + 0x80; 
    utf8buffer[2] = ((codepoint >> 6) & 0x3F) + 0x80;
    utf8buffer[3] = (codepoint & 0x3F) + 0x80;
    utf8buffer[4] = NUL;
    RT 4;
  } EL { RT 0; } // out of range
}

IN repeatutf8(IN codepoint, IN numtimes) {
  CH charbuffer[MAXUTF8CHARLEN];
  IN charlen = utf8thischar(codepoint, charbuffer);
  IN totallen = 0;
  IN ni = -1;
  WI (INC ni LT numtimes) {
    printf("%s", charbuffer);
    totallen ADDS charlen;
  }
  RT totallen;
}

#define U1(cp)       repeatutf8(cp, 1)
#define Un(cp, nt)   repeatutf8(cp, nt)
