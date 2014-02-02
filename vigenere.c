// Program to encrypt text with vignere cipher //

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int i,j,k;
	int temp,temp1 = 97;
	char vig_square[26][26];
	char plain[50];
	char key[20];
	char cipher[50];
	char *f_key;
	//Filling the vigenere square //
	for(i = 0;i<26;++i){
		temp = temp1++;
		for(j = 0;j<26;++j){
			if(temp>122){
				temp = 97;	
			}
			vig_square[i][j] = (char)temp++;
		}
	}
	printf("\n");
	//displaying the v square //
	for(i = 0;i<26;++i){
		for(j = 0;j<26;++j){
			printf("%c ",vig_square[i][j]);	
		}
		printf("\n");
	}
	printf("\n\n");
	printf("\t*** PART ONE : ENCRYPTION ***\n");
	printf("\nEnter your plain text:\n");
	scanf("%[^\t\n]s",plain);
	int p_len = strlen(plain);
	printf("\nEnter your key to decrypt:\n");getchar();
	scanf("%[^\t\n]s",key);
	int k_len = strlen(key);
	//Algo to repeat the key to make the length equal to plain text //
	f_key = (char*)malloc(sizeof(char)*p_len);
	int times = p_len / k_len;
	int rem = p_len % k_len;
	int ind = 0;
	while(times>0){
		for(i = 0;i<k_len;++i){
			f_key[ind++] = key[i];
		}
		times--;
	}
	for(i = 0;i<rem;++i){
		f_key[ind++] = key[i];
	}
	printf("\nThe key to encrypt is:\n");
	printf("%s",f_key);
	printf("\n");
	//Actual encryption algorithm //
	printf("\nEncrypted text is:\n");
	int row,col,i1;
	for(i = 0;i<p_len;++i){
		for(i1 = 0;i1<26;++i1){
			if(vig_square[i1][0] == f_key[i]){
				row = i1;
			}
			if(vig_square[0][i1] == plain[i]){
				col = i1;
			}
		}
		printf("%c",vig_square[row][col]);
		row = col = 0;
	}
	printf("\n\n");
	printf("\t*** PART TWO : DECRYPTION ***\n");
	printf("Enter cipher text to decrypt:\n");getchar();
	scanf("%[^\t\n]s",cipher);
	printf("\n\nEncrypted text is:\n");
	int c_len = strlen(cipher);
	for(i = 0;i<c_len;++i){
		for(i1 = 0;i1<26;++i1){
			if(vig_square[i1][0] == f_key[i]){
				row = i1;
			}
			for(j = 0;j<26;++j){
				if(vig_square[row][j] == cipher[i]){
					col = j;
				}
			}
		}
		printf("%c",vig_square[0][col]);
		row = col = 0;
	}
	return 0;
}
