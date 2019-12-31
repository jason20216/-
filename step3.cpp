#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int RACE_END = 70;

void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr );
void moveTortoise( int *const );
void moveHare( int * const );

int main()
{
    int tortoise=1;
    int hare = 1;
    clock_t start,end;
    srand( time( 0 ) );
    
    start=clock();
    while ( tortoise != RACE_END && hare != RACE_END ) 
   {
      Sleep( 100 );
      system("cls");
	      
      moveTortoise( &tortoise );
      moveHare(&hare);
      printCurrentPositions( &tortoise, &hare );
      
   }
   end=clock();
   if(tortoise==RACE_END) cout<<"TORTOISE WINS!!!YAY!!!"<<endl;
   else if(hare==RACE_END) cout<<"Hare wins. Yuch."<<endl;
   cout<<"TIME ELAPSED = "<<(end-start)/1000<<" seconds";
}

/*印出烏龜與兔子位置*/
void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr )
{
	for(int i=1;i<=7;i++)
		cout<<"---------|";
		cout<<endl;
	cout<<setw(*bunnyPtr)<<"H"<<endl;
	cout<<setw(*snapperPtr)<<"T"<<endl;
}

/*移動烏龜*/
void moveTortoise( int * const turtlePtr )
{
	int a;
	a=(rand()%10);
	if(a>=1 && a<=5) *turtlePtr+=3;
	else if(a>=6 && a<=7) *turtlePtr-=6;
	else if(a>=8 && a<=10) *turtlePtr-=1;
	
	if(*turtlePtr>70 ) *turtlePtr=70;
	else if(*turtlePtr<1) *turtlePtr=1;
}

/*移動兔子*/
void moveHare( int * const rabbitPtr )
{
  int b;
  b=(rand()%10);
  if(b>=1 && b<=2) *rabbitPtr+=9;
  else if(b==3) *rabbitPtr-=12;
  else if(b>=4 && b<=6) *rabbitPtr+=1;
  else if(b>=7 && b<=8) *rabbitPtr-+2;
  
  if(*rabbitPtr>70 ) *rabbitPtr=70;
  else if(*rabbitPtr<1) *rabbitPtr=1;
}
