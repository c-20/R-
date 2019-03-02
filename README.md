# R:
web browser tree interface for viewing and downloading files

Compile using gcc: rename Rdrive.c to R:.c and run ./Rdrive.gcc

Program should run in /cgi-bin/ or equivalent.

Program outputs HTTP packets corresponding to the given query string.

Program is 1-level recursive - it loads itself in an iframe with a subtree query to access tree data or files.

Next step: improve browser compatibility for media file playback, drag-drop uploads, code sections and references

Todo: .det file support

-> table of data columns indicating addresses of file features and their significant details (e.g. timenow, timelen)

-> det symbolic links - integrate with file system later

Todo: commands:

-> create a file with suffix : to map the corresponding command. flip switches to create alternative outputs
