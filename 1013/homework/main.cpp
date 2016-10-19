#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define POLY_MAX 10
#define ACT_LEN 8

struct variable{
	float coe;
	int exp;
};

struct mypoly{
	variable var[POLY_MAX];
	int length;

	void ReadData(char *filename);
	void ShowPoly();
	mypoly Add(mypoly);
	void SingelMult(int);
	int Lead_Exp();
	void Attach(float,int);
	void Remove(int);
	mypoly Mult(mypoly);

	mypoly(){
    length = 0;
	};

	mypoly(char *filename){
		FILE *fptr;
		fptr = fopen(filename,"r");
		length = 0;
		while(!feof(fptr)){
			fscanf(fptr,"%f %d",&var[length].coe,&var[length].exp);
			length++;
		}
		fclose(fptr);
	};
};

int main(){
  int opt,p,mult;
  bool over = false;
  mypoly A,B;
	char *action[ACT_LEN];
	action[0]="Ū�J�h����\n";
	action[1]="�L�X�h�������e\n";
	action[2]="�h�����ۥ[\n";
	action[3]="�h�������W�@�ƭ�\n";
	action[4]="�L�X�h�������̤j���ƪ��Y��\n";
	action[5]="�s�W����\n";
	action[6]="�R���h������������\n";
	action[7]="�h�����ۭ�\n";

	A.ReadData("a.txt");
  B.ReadData("b.txt");

  while(!over){
    for(int i=0;i<ACT_LEN;i++){
      printf("%d. %s",i+1,action[i]);
    }
    printf("��L. ���}���{��\n\n");
    printf("�п�� : ");
    scanf("%d",&opt);
    printf("\n");
    switch(opt){
      case 1:
        A.ReadData("a.txt");
        B.ReadData("b.txt");
        break;
      case 2:
        printf("�h����1:");
        A.ShowPoly();
        printf("�h����2:");
        B.ShowPoly();
        break;
      case 3:
        break;
      case 4:

        printf("�п�J�n�ާ@���Ӧh����:");
        scanf("%d",&p);
        if(p!=1 && p!=2){
          printf("��J���~,�Э��s����\n");
          break;
        }
        printf("�п�J�n���W���ӥ����:");
        scanf("%d",&mult);
        if(p==1){
          A.SingelMult(mult);
        }
        if(p==2){
          B.SingelMult(mult);
        }
        break;
      case 5:
        printf("�п�J�n�L�X���Ӧh��������ɫY��:");
        scanf("%d",&p);
        if(p!=1 && p!=2){
          printf("��J���~,�Э��s����\n");
          break;
        }
        printf("\n�h����%d����ɫY�Ƭ�%",p);
        if(p==1){
          printf("%d\n",A.Lead_Exp());
        }
        if(p==2){
         printf("%d\n",B.Lead_Exp());
        }
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      default:
        over = true;
        printf("���}�{�Ǥ�...");
    }
    printf("------------------\n\n");
  }
	return 0;
}

void mypoly::ReadData(char *filename){
  FILE *fptr;
  fptr = fopen(filename,"r");
  length = 0;
  while(!feof(fptr)){
    fscanf(fptr,"%f %d",&var[length].coe,&var[length].exp);
    length++;
  }
  fclose(fptr);
}

void mypoly::ShowPoly(){
  variable temp;
	for(int i=0;i<length;i++){
    for(int j=i;j<length;j++){
      if(var[i].exp<var[j].exp){
        temp = var[i];
        var[i] = var[j];
        var[j] = temp;
      }
    }

		if(i==length-1){
			printf("%.0fX^%d\n",var[i].coe,var[i].exp);
		}else{
      printf("%.0fX^%d + ",var[i].coe,var[i].exp);
		}
	}
}

void mypoly::SingelMult(int c){
	for(int i=0;i<length;i++){
		var[i].coe = var[i].coe * c;
	}
}

int mypoly::Lead_Exp(){
  variable temp;
  temp.exp=0;
  for(int i=0;i<length;i++){
    if(temp.exp < var[i].exp){
      temp.exp = var[i].exp;
      temp.coe = var[i].coe;
    }
  }
  return temp.coe;
}
