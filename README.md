# R:
web browser tree interface for viewing and downloading files

Compile using gcc: rename Rdrive.c to R:.c and run ./Rdrive.gcc

Program outputs HTTP packets corresponding to the given query string.

Program is 1-level recursive - it loads itself in an iframe with a subtree query to access tree data or files.

Program should run in /cgi-bin/ or equivalent.

Next step: improve browser compatibility for media file playback, drag-drop uploads, file sections

Todo: .det file support

-> table of data columns indicating addresses of file features and their significant details (e.g. timenow, timelen)
