#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myhtml.h"
#include "lsday.h"
#include <time.h>

void PutDays(){
    printf("<tr><td bgcolor =\"#ee82ee\">日</td><td>月</td><td>火</td><td>水</td><td>木</td><td>金</td><td bgcolor =\"#00bfff\">土</td></tr>");
}

int main(){
    int i,j,m,x,y,w,len,day,d;
    int year,month;
    
    time_t sec;
    struct tm *tp;
    sec = time(NULL);
    tp = localtime(&sec);
    
    char uid[80],buf[32];
    char* query;
    char* ptr;
    char* env;

    env = getenv("QUERY_STRING");
    strncpy(buf,env,sizeof(buf));
    //fgets(buf,sizeof(buf),stdin);    
    putContentType();

    ptr = strtok(buf,"=");
    ptr = strtok(NULL,"&");

    year = atoi(ptr);
    
    ptr = strtok(NULL,"=");
    ptr = strtok(NULL,"&");
    month = atoi(ptr);

    putHTMLheader("Calendar_Zeller");

    day = 1;
//    PutDays();

    y = year;
    m = month;
    d = 1;
    if(month < 3){
        y--;
	m += 12;
    }
    x = (m * 13 + 8) / 5;
    y += y / 4 - y / 100 + y / 400;
    w = (y + x + d) % 7;
    
   // printf("<a href = \" PREV \">    
    printf("<form action=\"calendar_zeller.cgi\" method=\"GET\"> YEAR:<input name=\"year\" type=\"text\" size=\"4\" maxlength=\"4\" value=\"%d\">",year);
     printf("<select name= \"month\"> \n <option selected=\"selected\"> %d </option>",month);
     puts("<option value= \"1\"> 1月</option>");
     puts("<option value= \"2\"> 2月</option>");
     puts("<option value= \"3\"> 3月</option>");
     puts("<option value= \"4\"> 4月</option>");
     puts("<option value= \"5\"> 5月</option>");
     puts("<option value= \"6\"> 6月</option>");
     puts("<option value=\"7\"> 7月</option>");
     puts("<option value=\"8\"> 8月</option>");
     puts("<option value=\"9\"> 9月</option>");
     puts("<option value=\"10\"> 10月</option>");
     puts("<option value=\"11\"> 11月</option>");
     puts("<option value=\"12\"> 12月</option>");
     puts("</select>");
    
    
    printf("<input type=\"submit\" value=\"Show\"></form> ");
    
    if(month > 1){
        printf("<a href=\"calendar_zeller.cgi?year=%d&month=%d\">PREV</a>\n",year,month - 1);
    }else{
        printf("<a href=\"calendar_zeller.cgi?year=%d&month=%d\">PREV</a>\n",year - 1,12);
    }
    if(month < 12){
        printf("<a href=\"calendar_zeller.cgi?year=%d&month=%d\">NEXT</a>\n",year,month + 1);
    }else{
        printf("<a href=\"calendar_zeller.cgi?year=%d&month=%d\">NEXT</a>\n",year + 1,1);
    }
    puts("<table border = \"1\" align=\"center\" valign=\"middle\">");
    printf("<caption>%d年%d月のカレンダー</caption>",year,month);
    PutDays();
    for(i = 0; i < 6 && (day - 1 != LastDay(year,month)); i++){
        puts("<tr>");
	for(j = 0; j < 7; j++){
	    if(day - 1 == LastDay(year,month)){
	        printf("</td>");
		break;
            }		
	    
	    if(day == tp->tm_mday && year == tp-> tm_year+1900 && month == tp->tm_mon+1){
	    	puts("<td bgcolor =\"#adff2f\">");
	    }else if(j==0){			  
	        puts("<td bgcolor =\"#ee82ee\">");	
	    }else if(j == 6){
	        puts("<td bgcolor =\"#00bfff\">");			
            }else{
	        printf("<td>");							
	    }
	    
	    //if(i == 0 && j <= tp -> tm_wday - tp -> tm_mday % 7 ){
	    if(i == 0 && j < w ){
	        printf("</td>");
		continue;                                                                   }					
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
