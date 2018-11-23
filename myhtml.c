/* HTML */
#include <stdio.h>

void putContentType(void)
{
    puts("Content-Type: text/html\n");
}

void putHTMLheader(const char* title)
{
    puts("<html>");
    printf("<head><title>%s</title>",title);
    puts("<style type=\"text/css\">\n <!--th,td{ font-size:23pt; } --> </style>\n</head>");
    puts("<body>");
}

void putHTMLfooter(void)
{
    puts("</body>\n</html>");
}





