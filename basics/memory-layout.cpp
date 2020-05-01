int x=1; // increase size of Initiallized data segment by 4
int xx; //increases size of bss segment by 4
static int j=9; //increases init data segment by 4
static int jj; //incresases uninit data(bss) segmement by 4
int main(){
  int n=0;
  static int i;  //increase bss segment by 4
}

/*Memory layout of a progrmam

linux shell:
g++ memory-layout.cpp -o memory
size memory 

  *******************
  *    Stack        *
  *      |          *
  *      \/         *
  *******************
  *     /\          *
  *      |          *
  *      Heap       *
  *******************
  *Bss (uninit data)*
  *******************
  *Initiallized data*
  *******************
  *Text             *
  *******************

  */
