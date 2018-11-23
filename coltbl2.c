/* Color table2*/
#include <stdio.h>
#include "myhtml.h"

int main(){
    int r=0xff,g,b;
    char str[8];
    putContentType();
    putHTMLheader("Color Table2");
    
    puts("<table>");
    puts("<caption>Color table1</caption>");
    for(b = 0;b <= 0xff; b += 0x11){
        for(g = 0; g <= 0xff; g += 0x11){
	    sprintf(str,"#%02X%02X%02X",r,g,b);
	    printf("<td bgcolor=\"%s\">%s</td>",str,str);
	}
	puts("</tr>");
    }
    puts("</table>");
    r = 0;
    b = 0;
    r = 0;
    
    
    puts("<table>");
    puts("<caption>Color table2</caption>");
    for(r = 0;r <= 0xff; r += 0x11){
        for(g = 0; g <= 0xff; g += 0x11){
	    sprintf(str,"#%02X%02X%02X",r,g,b);
	    printf("<td bgcolor=\"%s\">%s</td>",str,str);
	}						       
	puts("</tr>");
    }
    puts("</table>");
    r = 0;
    b = 0;
    g = 0;

    puts("<table>");
    puts("<caption>Color table3</caption>");
    for(b = 0;b <= 0xff; b += 0x11){
        for(r = 0; r <= 0xff; r += 0x11){
	    sprintf(str,"#%02X%02X%02X",r,g,b);
	    printf("<td bgcolor=\"%s\">%s</td>",str,str);
	}
        puts("</tr>");
    }
    puts("</table>");
    putHTMLfooter();
    return 0;
}

