/* Color table*/
#include <stdio.h>

int main(){
    int r=0xff,g,b;
    char str[8];

#if defined(CGI)
    puts("Content-Type: text/html\n");
#endif /*CGI*/
    puts("<html>\n<head><title>Color table</title></head>");
    puts("<body>");
    puts("<table>");
    puts("<caption>Color table</caption>");
    for(b = 0;b <= 0xff; b += 0x11){
        for(g = 0; g <= 0xff; g += 0x11){
	    sprintf(str,"#%02X%02X%02X",r,g,b);
	    printf("<td bgcolor=\"%s\">%s</td>",str,str);
	}
	puts("</tr>");
    }
    puts("</table>\n</body>\n</html>");
    return 0;
