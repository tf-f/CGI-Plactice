#include <stdio.h>
#include <time.h>
#include "myhtml.h"
#include "lsday.h"

void PutDays(){
    printf("<tr><td bgcolor =\"#ee82ee\">��</td><td>��</td><td>��</td><td>��</td><td>��</td><td>��</td><td bgcolor =\"#00bfff\">��</td></tr>");    
}
int main(){
    time_t sec;
    struct tm *tp;
    sec = time(NULL);
    tp = localtime(&sec);
    
    putContentType();
    putHTMLheader("Calendar");	  
    int i,j,year,month,day;

    year = tp -> tm_year + 1900;
    month = tp -> tm_mon + 1;
    //����������ɽ����
    
    puts("<table border = \"1\" align=\"center\" valign=\"middle\">");
    printf("<caption>%dǯ%d��Υ�������</caption>",year,month);
    day = 1;
    PutDays();
    for(i = 0; i < 6 && (day - 1 != LastDay(year,month)); i++){
        puts("<tr>");
        for(j = 0; j < 7; j++){

	    if(day - 1 == LastDay(year,month)){
	        printf("</td>");
	        break;
	    }

	    if(day == tp-> tm_mday){
	        puts("<td bgcolor =\"#adff2f\">");
	    }else if(j==0){
	        puts("<td bgcolor =\"#ee82ee\">");  
            }else if(j == 6){
	        puts("<td bgcolor =\"#00bfff\">");
	    }else{
	        printf("<td>");
            }

            if(i == 0 && j < ( tp -> tm_wday - tp -> tm_mday) % 7 ){
	        printf("</td>");
		continue;		
	    }
	    printf("%d",day);
	    day++;
	    puts("</td>");
	}
	puts("</tr>");
    }
    puts("</table>\n</body>\n</html>");
    putHTMLfooter(); 
    return 0;
    
}
