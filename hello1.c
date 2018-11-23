/* Hello World -CGI Version */
#include <stdio.h>
int main(){
	printf("Content-Type: text/html\n\n");
	printf("<html>\n");
	printf("<head><title>Hello</title></head>\n");
	printf("<body>\n");
	printf("Hello World\n");
	printf("</body>\n");
	printf("</html>\n");
	return 0;

}
