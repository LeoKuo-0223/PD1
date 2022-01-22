// #include <stdio.h>

// void p(char *str, int n) {
// char ch ;
// int i ;
// if(n==1) {
//   printf("%s\n", str) ;
// }
// else {
//   for(i=n-1 ; i>=0 ; i--) {
//       ch = *(str+i) ;
//       *(str+i) = *(str+n-1) ;
//       *(str+n-1) = ch ;
//       p(str, n-1) ;
//       ch = *(str+i) ;
//       *(str+i) = *(str+n-1) ;
//       *(str+n-1) = ch ;
//   }
// }
// }

// int main() {
// char ch[] = "abcd" ;
// p(ch, 4) ;
// system("pause") ;
// return 0 ;
// }