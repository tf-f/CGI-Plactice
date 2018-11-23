/* 99 table */
#include <stdio.h>

int main(){
    int x,y;
#if defined (CGI)
    puts("Content-Type: text/html\n");
#endif /* CGI */
    puts("<html>");
    puts("<head><title>99 table</title></head>");
    puts("<body>");
    puts("<table border=\"1\">");
    puts("<caption>99 Table</caption>");
    for(y = 1; y <= 9; y++){
        printf("<tr>");
	for(x = 1; x <= 9; x++){
	    printf("<td>%2d</td>",x*y);
	}
	puts("</tr>");
    }
    puts("</table>\n</body>\n</html>");
    return 0;
}
