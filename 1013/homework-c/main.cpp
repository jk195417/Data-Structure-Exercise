#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define POLY_MAX 30
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
  int opt,p,mult,add_e,re_e;
  float add_c;
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
        printf("�h�����ۥ[���G:");
        A.Add(B).ShowPoly();
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
        printf("\n�h����%d����ɫY�Ƭ�",p);
        if(p==1){
          printf("%d\n",A.Lead_Exp());
        }
        if(p==2){
         printf("%d\n",B.Lead_Exp());
        }
        break;
      case 6:
        printf("�п�J�n�ާ@���Ӧh����:");
        scanf("%d",&p);
        if(p!=1 && p!=2){
          printf("��J���~,�Э��s����\n");
          break;
        }
        printf("�п�J�n�[�W�������Y��:");
        scanf("%f",&add_c);
        printf("�п�J�n�[�W����������:");
        scanf("%d",&add_e);
        if(p==1){
          A.Attach(add_c,add_e);
        }
        if(p==2){
          B.Attach(add_c,add_e);
        }
        break;
      case 7:
        printf("�п�J�n�ާ@���Ӧh����:");
        scanf("%d",&p);
        if(p!=1 && p!=2){
          printf("��J���~,�Э��s����\n");
          break;
        }
        printf("�п�J�n����������������:");
        scanf("%d",&re_e);
        if(p==1){
          A.Remove(re_e);
        }
        if(p==2){
          B.Remove(re_e);
        }
        break;
      case 8:
        printf("�h�����ۭ����G:");
        A.Mult(B).ShowPoly();
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

mypoly mypoly::Add(mypoly p2){
  mypoly temp1;
  temp1.length = length;
  mypoly temp2=p2;

  for(int i=0;i<temp1.length;i++){
    temp1.var[i] = var[i];
    for(int j=temp2.length-1;j>=0;j--){
      variable temp_v;
      if(temp1.var[i].exp==temp2.var[j].exp){
        temp_v = temp2.var[j];
        temp2.var[j] = temp2.var[temp2.length-1];
        temp2.var[temp2.length-1] = temp_v;
        temp1.var[i].coe += temp2.var[temp2.length-1].coe;
        temp2.length--;
        break;
      }
    }
  }
  for(int k=0;k<temp2.length;k++){
    temp1.var[length+k]=temp2.var[k];
    temp1.length++;
  }
  return temp1;

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

void mypoly::Attach(float c,int e){
  bool same_exp = false;
  for(int i=0;i<length;i++){
    if(var[i].exp==e){
      var[i].coe += c;
      same_exp = true;
      break;
    }
  }
  if(!same_exp){
    var[length].coe = c;
    var[length].exp = e;
    length++;
  }
}

void mypoly::Remove(int e){
 float c=0.0;
  for(int i=0;i<length;i++){
    if(var[i].exp == e){
      c = var[i].coe;
      var[i] = var[length-1];
      var[length-1].coe=0;
      var[length-1].exp=0;
      length--;
      printf("%.0fx^%d�wRemove\n",c,e);
      break;
    }
  }
  if(c==0){
    printf("�S�����o�Ӧ��誺����\n");
  }
}

mypoly mypoly::Mult(mypoly p2){
  mypoly total;
  for(int i=0;i<length;i++){
    mypoly temp;
    for(int j=0;j<p2.length;j++){
      temp.var[j].coe = var[i].coe * p2.var[j].coe;
      temp.var[j].exp = var[i].exp + p2.var[j].exp;
      temp.length++;
    }
    total = total.Add(temp);
  }
  return total;
}
