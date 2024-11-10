#include<iostream>
#include<cstring> // для использования си строк 
#include<cstdlib> // для очистки экрана 
#include <conio.h> // для выделения памяти 
#include <fstream> //Файловый вывод
#include <windows.h> 
 
using namespace std;
 
 
 class Input
 	 	{
 	 		   
			  private:
			  char** text; //Указатель на двухмерный массив символов
		  	  char razdel[6];
			  char zamena ;
			  int stolb; 
			  bool status; // Определяет пустой ли объект
			  public:
			  	
				void set_razdel()    
			    {
			  		cout<<"Vvedite razdeliteli:" ;  	
				  	 
    				 
    				while(cin.get() != '\n'); // поимка лишних /n
					gets(razdel);
					 
					
					cout<<endl;
			    }
		
			  	void set_text()
			    {
				     status = 1;
					 char buffer[102];
				     stolb =-1;
				     		do
								{
			
									gets(buffer);
		 							if(strlen(buffer)>101)
									{
										cout<<endl;
										cout<<"Vvedite sroku zanovo"<<endl;
									}  
			
									else
									{
										stolb++;
										text=(char**)realloc(text,(stolb+1)*sizeof(char*));
										text[stolb]=(char*)calloc((strlen(buffer)+1),sizeof(char));
										strcpy(text[stolb],buffer);
									}		 
								
								if(strlen(buffer)<30)
								{
									break;
								}
					
			  
				 
								} while(1);
					 
				
				}
				
				void set_zamena()
				{
					cout<<"Vvedite zamenu:";
					cin>>zamena;
					cout<<endl;
				}
				
				bool if_stolb() //Проверка введёности текста 
				{
					if(status==0)
					{
						return 0;
					}
					return 1;
				}
				bool if_zamena() //Проверка введёности замены
				{
					if(zamena == '\0')
					{
						return 0;
					}
						return 1;
				}
				
			
				
				Input()
				{
					text =(char**)(calloc(1,sizeof(char*))) ;
					stolb = 0;
					zamena ='\0';
					
					status = 0;
				}
			 
			friend class Work; //Для передачи объекта
			friend class Out;
		};

  
 class Work
 		{
 		  	public:
		   
		    int  razdel_if (char  razd[6], char s) 
			{ 
				for(int i=0;i<5;i++) // Пробегаеи до 5 так как 
			  	{               
			  		if( razd[i]==s)
			  		return 1;
				}
			
			return 0;
			}
			
			int sum_word( char razd[6],char str[] )
			{
				int i =-1;
				int s =0 ;
				bool status  =0;
				while(1)
				{
					i++;
					if(str[i]=='\0') {break;}
					if(razdel_if( razd ,str[i])) 
					{status  =  0;}
					
					else
						{
							if(status == 0)
							 	{
									s++;
									status =1;	 
								}	
						}
				}
				
				return s;	
			}
		    
			bool glas_if(char s) 
			{
			
			
					string str = "AIOEUYaioeuy";
					int i=-1;
					while(1)
					{
						i++;
						if(str[i]=='\0') {break;} 
						if(str[i]==s) {return 1;}
					}
			 return 0;	
			}
			
			void  change( char razd[6], char zamen, char str[] )
			{
				int i=-1;
				if(sum_word(razd,str)>5)
				{
				
					while(1)
					{
				
						i++;
						if(str[i] =='\0') {break;}
						
						if(glas_if(str[i])) {str[i]=zamen;}
					}
				}	
			}
			
			void  working(Input &y)
			{
				for(int i = 0; i<y.stolb+1 ; i++)
				{
					change(y.razdel, y.zamena,y.text[i] );
				}
				
			}
			
				
		
		};
 
 
 class Out
 		{	
 		public:
		 void show(Input y)
			 {
				for(int i = 0; i<y.stolb+1;i++)
 				{
 			 		int k=-1;	
			 		cout<<endl;	
			 		k++;
					cout<<y.text[i];	
			 		if(y.text[i][k]=='\0')
			 			{
			 				break;	
						}
					   				
				}		 		 
			 }	
		
		 void zapis(Input y, ofstream &f)
			{	
				
				f.open("Kursach.txt");
				for(int i = 0; i<y.stolb+1;i++)
 				{
 			 		
			 		f<<endl;	
			 		
					f<<y.text[i];	
			 		
					   				
				}		 		 
			 	f.close();
			 }	
		};	
  	
int main()
{ 
 	
	Input vvod;
	Work  proc;
	Out  vivid;
	ofstream fael("Kursach.txt");
	
	begin:
	{
	
	/*
	float n = 1.5;
	float l = 0.75;
	*/}
	
	char chois='0';
	char s;
	
	cout<<endl;
	cout<<"Menu"<<endl;
	cout<<"1)Vvesti text"<<endl;
	cout<<"2)Obravotat text"<<endl;
	cout<<"3)Vvesti razdeliteli i symvol zameni"<<endl;
	cout<<"4)Vivesti text"<<endl;
	cout<<"5)Vixod"<<endl;
	cout<<"Vibirete deystvie->";
	
	cin>>chois;
	cout<<endl;
	 
	switch (chois)
	{
		case '1': // Ввод текста
			{
				while(cin.get() != '\n');	
				vvod.set_text();
				system("cls");
				cout<<"Well done";
			 	
				 
			
				
				break;
			}
		
		case '2': //Обработка
			{
				if(((vvod.if_stolb())*(vvod.if_zamena()))==0)
					{
						system("cls");
						cout<<"Eror"<<endl;
					
					}
				else
					{
						system("cls");
						
						proc.working(vvod); 	
							
							
						 
						cout<<"Well done ";
						 
					}
				 
				
				 	
				break;
			}
		
		case '4': // Вывести и записать текст 
			{
				if(vvod.if_stolb()==0)
				{
					system("cls");
					cout<<"Eror"<<endl;
					
					
				}
				else
				{
					
					vivid.show(vvod);
					
					cout<<endl;
					cout<<endl;
					cout<<"Zapisat text v fail"<<endl;
					cout<<"Y/N"<<endl;
					char ch;
					cin>>ch;
					if((ch=='Y')||(ch=='y'))
					{
						
						vivid.zapis(vvod, fael);	 
						vivid.zapis(vvod, fael);
						 
					}
					
				
				system("cls");
				cout<<"Well done"<<endl;
				
				}
				break;
			}
		
		case '3': // Ввод разделителей и замены
			{
					 
					
					vvod.set_razdel();
					vvod.set_zamena();
					
					system("cls");
					cout<<endl;
					cout<<"Well done"<<endl;
					
					break;
			}
		
		case '5': //Выход из програмы  
			{				/*
							Beep(329.63*n,450*l);
							Beep(440*n,450*l);
							Beep(523.25*n,450*l);
				
							Beep(329.63*n,450*l);
							Beep(440*n,450*l);
							Beep(523.25*n,450*l);
				
							Beep(329.63*n,450*l);
							Beep(440*n,450*l);
				
							Beep(297.66*n,450*l);
							Beep(392*n,450*l);
							Beep(493.88*n,450*l);
				
							Beep(297.66*n,450*l);
							Beep(392*n,450*l);
							Beep(493.88*n,450*l);
				
							Beep(297.66*n,450*l);
							Beep(392*n,450*l);
				
							Beep(261.63*n, 450*l);
							Beep(349.23*n, 450*l);
							Beep(440*n,450*l);
				
							Beep(261.63*n, 450*l);
							Beep(349.23*n, 450*l);
							Beep(440*n,450*l);
							
							Beep(261.63*n, 450*l);
							Beep(349.23*n, 450*l);
						
							Beep(297.66*n,450*l);
							Beep(349.23*n, 450*l);
							Beep(440*n,450*l);
				
							Beep(297.66*n,450*l);
							Beep(349.23*n, 450*l);
							Beep(440*n,450*l);
			
							Beep(297.66*n,450*l);
							Beep(349.23*n, 450*l);
							*/
				goto end;
				break;	
			}
		default:
			{
				system("cls");
				cout<<"Oshbka poprubuyte snova"<<endl;
				
				goto begin;
			}
	
	}
	
 	 	goto begin;	 
	 
end: ; 	 // Флаг для выхода 	
	 
	 
	return 0;
}
