#include<iostream>
#include<vector>
#include <fstream>
#include <string>
using namespace std;

int add(int a, int b)
{

	int c=a+b;
	return c;


}

int sub(int a, int b)
{

	int c=a-b;
	return c;


}

int mul(int a, int b)
{

	int c=a * b;
	return c;


}

int divide (int a, int b)
{

	int c = a / b;
	return c;


}



class Variable {
public :
    int value;
	string name;
  

public:
    void set_values (int a, string b)
	{
	    value=a;
		name=b;
	}

	 int get_values ()
	{
	   return value;
	}
    
	

};






int interpret(string name)
{
  	
	
	
	 vector<char *> v;
	string  line;

int x=0;
int z=0;
string dum;
  ifstream myfile1 (name);
  if (myfile1.is_open())
  {
    while ( getline (myfile1,dum) )
    {
      x++;
        char *linev= new char[dum.length() + 1];
       strcpy(linev, dum.c_str());
	   dum = strtok (linev," ");
	  char *line2 = "Let";
        
	  if( strcmp(linev,line2 )==0 )
	  { 
		  z++;
	  }

    }
    myfile1.close();


  }

  else
  {cout << "Unable to open file"; 
     return 0;
  
  }
  

  Variable* obj1;
  obj1 = new Variable [z];

  int num=x;

  ifstream myfile (name);
  if (myfile.is_open())
  {

for(int j=0;j<num;j++)
{
     getline (myfile,line); 
    
     

	   char *line1 = new char[line.length() + 1];
	   char *line11 = new char[line.length() + 1];
	   char *linev = new char[line.length() + 1];
	   char *linep = new char[line.length() + 1];
       strcpy(line1, line.c_str());
	   strcpy(line11, line.c_str());
	   strcpy(linev, line.c_str());
       strcpy(linep, line.c_str());
       

      line1 = strtok (line1," ");
	  linep = strtok (linep," ");
	  char *line2 = "Let";
	  char *line3 = "print";

   
	  if( strcmp(linep,line3 )==0 )
	  { 
		  
		  
						while (linep != NULL)
                    {
                        
                          linep = strtok (NULL, " ");
						  break;
                    }
		   
		   
		  

		   if(linep[0]== '"')
		   {
			   cout<<endl;
		       cout<<linep;
			   cout<<endl;
		   
		   }

		   else
		   {
			   int f=0;
		       for(int y=0;y<z;y++)
					{
						char *a1 = new char[obj1[y].name.length() + 1];
                             strcpy(a1, obj1[y].name.c_str());
					   if(strcmp(a1,linep)==0)
					   {
						   cout<<endl;
						   cout<<obj1[y].value;
						   cout<<endl;
						   f=1;
						   break;
					   }

			       }

			   if(f==0)
			   {
			      cout<<"\nSyntax error\n";
					return 0;  
			   
			   }
		   }


	  }

	  else if( strcmp(line1,line2 )==0 )
	  { //
	    int a=4;
		
	    if(isdigit(line[a]))
		{
		     printf("\nSyntax error at line %d\n ",j);
			 return 0;
		}

		else
		{
		 
		  for(int i=5;i<7;i++)

		  {
		     
			  char *a = "=";
			  if ( line11[i]=='=')
			 {
		        	    line11 = strtok (line11,"=");
						
						while (line11 != NULL)
                    {
                        
                          line11 = strtok (NULL, "=");
						  break;
                    }

                        line11 = strtok (line11," ");
						
						int a=atoi(line11);
			           
						

						
                       linev = strtok (linev,"=");
						linev = strtok (linev," ");
								while (linev != NULL)
                    {
                        
                          linev = strtok (NULL, " ");
						  break;
                    }
                    string str(linev);

				   



					 obj1[j].set_values(a,str);

						
						
					   break;
			 }
		   
			
			 
			 
		  }
		}

	  }

	  else 
	  {
	         char *dum = new char[line.length() + 1];
	         strcpy(dum, line.c_str());
			 dum = strtok (dum," ");

			
			 int flag=0;
			 int value1=0;
			  
			 char* dumz = "=";
			  char* dumz1 = "+";
			   char* dumz2 = "-";
			   char* dumz3 = "*";
			   char* dumz4 = "/";

			  

                 while (dum != NULL)
                {
                    
                    
					if(strcmp(dum,dumz)==0)
					{
					  
						flag=1;
					  
					    

					}

					else if(isdigit(*dum))
					{
					
					    if(flag==0)
						{
						    printf("\nSyntax error \n");
							return 0;
						
						}
						else
						{
					    v.push_back(dum);
						}
					
					}


					else if(strcmp(dum,dumz1)==0)
					{

						 if(flag==0)
						{
						    printf("\nSyntax error \n");
						      return 0;
						}
						else
						{ v.push_back(dumz1);}

					
					}

					else if(strcmp(dum,dumz2)==0)
					{

						 if(flag==0)
						{
						    printf("\nSyntax error \n");
						      return 0;
						}
						else
						{ v.push_back(dumz2);}

					
					}

					else if(strcmp(dum,dumz3)==0)
					{

						 if(flag==0)
						{
						    printf("\nSyntax error \n");
						     return 0;
						}
						else
						{ v.push_back(dumz3);}

					
					}

					else if(strcmp(dum,dumz4)==0)
					{

						 if(flag==0)
						{
						    printf("\nSyntax error \n");
						     return 0;
						}
						else
						{ v.push_back(dumz4);}

					
					}





					else
					{
						 int a=0;
                        
					for(int y=0;y<z;y++)
					{
						char *a1 = new char[obj1[y].name.length() + 1];
                             strcpy(a1, obj1[y].name.c_str());
					   if(strcmp(a1,dum)==0)
					   {
					             a=1;

								if(flag==1 )
								{
								
								  
									v.push_back(a1);
								    
								
								}

								

					   }


					
					}

					if(a==0)
					{
					
					   printf("\nSyntax error .. variable not declared\n");
					   return 0;

					}

				 }


					


					 dum = strtok (NULL, " ");
                    
                }

				 
				int g=0;


                 for (int i=0; i<v.size();i++)
				 {
                           
					 int dummy=0;
					    char * add1= "+";
						char * sub1= "-";
						char * mul1= "*";
						char * div1= "/";

						  

						
						if(strcmp(v.at(i), add1)==0)
						{
						  int num1;
						  int num2;

						

							if (isdigit(*v.at(i-1)))
							{
							  

						     num1 = int( *v.at(i-1) - '0'); 

							}

							else
							{
							     
							for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,v.at(i-1))==0)
					                  {
							                 num1=  obj1[y].value;  
							          }

							}



							}

							if (isdigit(*v.at(i+1)))
							{
							  

						     num2 = int( *v.at(i+1) - '0'); 

							}

							else
							{
							
							    for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,v.at(i+1))==0)
					                  {
							                 num2=  obj1[y].value;  
							          }

							}
							
							}


							

							if(v.size()==i+2)
							 {
							
							    

								 char *zz = new char[line.length() + 1];
                                          strcpy(zz, line.c_str());

										    zz = strtok (linev," ");
					                   

								for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,zz)==0)
					                  {
							                  obj1[y].value=add(num1,num2);  
							          }
										

							   }

								
								
							
							 }

							 else
							 {
							 
							    dummy= add(num1,num2);

								char* buffer= new char[10];

							    itoa (add(num1,num2),buffer,10);

								v[i+1]=buffer;
								
								  


								
							 
							 }


							



							

							  

								
						
						}

						//

						if(strcmp(v.at(i), div1)==0)
						{
						  int num1;
						  int num2;

						

							if (isdigit(*v.at(i-1)))
							{
							  

						     num1 = int( *v.at(i-1) - '0'); 

							}

							else
							{
							     
							for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,v.at(i-1))==0)
					                  {
							                 num1=  obj1[y].value;  
							          }

							}



							}

							if (isdigit(*v.at(i+1)))
							{
							  

						     num2 = int( *v.at(i+1) - '0'); 

							}

							else
							{
							
							    for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,v.at(i+1))==0)
					                  {
							                 num2=  obj1[y].value;  
							          }

							}
							
							}


							

							if(v.size()==i+2)
							 {
							
							    

								 char *zz = new char[line.length() + 1];
                                          strcpy(zz, line.c_str());

										    zz = strtok (linev," ");
					                   

								for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,zz)==0)
					                  {
							                  obj1[y].value=divide(num1,num2);  
							          }
										

							   }

								
								
							
							 }

							 else
							 {
							 
							    dummy= add(num1,num2);

								char* buffer= new char[10];

							    itoa (divide(num1,num2),buffer,10);

								v[i+1]=buffer;
								
								  


								
							 
							 }


							



							 

							  

								
						
						}





						//

						if(strcmp(v.at(i), mul1)==0)
						{
						  int num1;
						  int num2;

						

							if (isdigit(*v.at(i-1)))
							{
							  

						     num1 = int( *v.at(i-1) - '0'); 

							}

							else
							{
							     
							for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,v.at(i-1))==0)
					                  {
							                 num1=  obj1[y].value;  
							          }

							}



							}

							if (isdigit(*v.at(i+1)))
							{
							  

						     num2 = int( *v.at(i+1) - '0'); 

							}

							else
							{
							
							    for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,v.at(i+1))==0)
					                  {
							                 num2=  obj1[y].value;  
							          }

							}
							
							}


							

							if(v.size()==i+2)
							 {
							
							    

								 char *zz = new char[line.length() + 1];
                                          strcpy(zz, line.c_str());

										    zz = strtok (linev," ");
					                   

								for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,zz)==0)
					                  {
							                  obj1[y].value=mul(num1,num2);  
							          }
										

							   }

								
								
							
							 }

							 else
							 {
							 
							    dummy= add(num1,num2);

								char* buffer= new char[10];

							    itoa (mul(num1,num2),buffer,10);

								v[i+1]=buffer;
								
								  


								
							 
							 }


							



							

							  

								
						
						}




						//

						if(strcmp(v.at(i), sub1)==0)
						{
						  int num1=0;
						  int num2=0;

						

							if (isdigit(*v.at(i-1)))
							{
							  

						     num1 = int( *v.at(i-1) - '0'); 

							}

							
							
							else
                              {
							    
								  if(v.at(i-1)[0]== '-')
								  {
								   num1 = int( *v.at(i-1) - '0'); 
								   num1=num1+1;
								  
								  }

								  else
								  {
							for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,v.at(i-1))==0)
					                  {
							                 num1=  obj1[y].value;  
							          }

							}
								  }


							}

							if (isdigit(*v.at(i+1)))
							{
							  

						     num2 = int( *v.at(i+1) - '0'); 

							}

							else
							{
							   if(v.at(i+1)[0]== '-')
								  {
								   num2 = int( *v.at(i+1) - '0'); 
								   num2=num2+1;
								  }

								  else
								  {
							    for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,v.at(i+1))==0)
					                  {
							                 num2=  obj1[y].value;  
							          }

							}
							   }
							
							}


							

							if(v.size()==i+2)
							 {
							
							    

								 char *zz = new char[line.length() + 1];
                                          strcpy(zz, line.c_str());

										    zz = strtok (linev," ");
					                   

								for(int y=0;y<z;y++)
					            {
						             char *a1 = new char[obj1[y].name.length() + 1];
                                          strcpy(a1, obj1[y].name.c_str());
					                    if(strcmp(a1,zz)==0)
					                  {
							                  obj1[y].value=sub(num1,num2);  
							          }
										

							   }

								
								
							
							 }

							 else
							 {
							 
							    dummy= sub(num1,num2);

								char* buffer= new char[10];

							    itoa (sub(num1,num2),buffer,10);

								v[i+1]=buffer;
								
								  


								
							 
							 }


							



							  

							  

								
						
						}


						


                     }
				

				





	  
	  }


}
    
    myfile.close();
  }

  else cout << "Unable to open file"; 

  


  return 0;

	
}