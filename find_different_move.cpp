/*
�������ܣ�
thesame.txt��д�������ļ�������ͬ���ļ������������ļ���Ϊ������ϵ��
�������Ŀ�ľ����ҳ������ļ��ж��ڱ������ļ��е��ļ������ƶ���destpath·���¡�
*/
#include <iostream>
#include <string>
#include <io.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h> 

using namespace std;
string dirpath = "F:\\��������\\Result\\C8053-new-pnt(1)\\";
string dirpath2 = "F:\\��������\\Result\\C8053-new-pnt(1)\\dirpath\\";
string destpath = "F:\\��������\\Result\\C8053-new-pnt(1)\\testmove\\";  
ofstream fout("F:\\��������\\Result\\C8053-new-pnt(1)\\thesame.txt");

int main(int args, char **argv)
{
    ifstream  fin("F:\\��������\\Result\\C8053-new-pnt(1)\\Cnew1.txt", std::ios::in);
 char  line[20]={0};
 std::string  x ;
 int i=0;
 while(fin.getline(line, sizeof(line)))
 {
     std::stringstream  word(line);
  word >> x;
        ifstream  fin("F:\\Result-change\\delete_new\\delete_new.txt", std::ios::in);
  char  line2[20]={0};
  std::string  y;
  while(fin.getline(line2, sizeof(line2)))
  {
     std::stringstream  word2(line2);
  word2 >>y;
   if (x==y)
    cout << y << endl;
    fout << y << endl;
    string newname = dirpath2 +y;
    string newname2 = destpath +y;

	//�ƶ�
 char *newNamePointer;
 char *newName2Pointer;
  newNamePointer = (char *)malloc((newname.size() + 1) * sizeof(char));
  newName2Pointer = (char *)malloc((newname2.size() + 1) * sizeof(char));
  strcpy(newNamePointer, newname.c_str());
  strcpy(newName2Pointer, newname2.c_str()); 
  MoveFileA (newNamePointer,newName2Pointer); 
  
  free(newNamePointer);
  free(newName2Pointer);

  }
 }
 fin.clear();
 fin.close();
 fout.close();
        return 0;
}