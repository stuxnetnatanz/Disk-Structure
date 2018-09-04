#include <iostream>
#include <fstream>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
//int r[4];
int sector_res;
static union typecast
{
    char str[4];
    int var;
}u;
struct structure
{
	char name[19];
    char t;
	int size;
	int  s_pos;
	int  e_pos;


}t;


union missed{
	structure fd;
	char str[32];
}entry;
int current;
char bufferin[512];

fstream f;
void sector_set()           //initial sector set
{   int total_sector,z,k,file_size,size;
	int i,j,a=65,sector_size=512;
    fstream f;
	f.open("this.txt",ios::in);
	if(f){

	int total_size;
		cout<<"file already exist opeining file";
		f.seekg(0,ios::end);
		size=f.tellg();
		total_size=size/1048576;
		cout<<endl<<"the file size is "<<total_size<<"MB";
		total_sector=size/sector_size;
		sector_res=(total_sector*4)/sector_size;
		current=sector_res*512;
		cout<<endl<<"the total no of sector are"<<total_sector<<endl<<"and total no of reserved sector are "<<sector_res;
		 f.close();
		 return;

	}

	cout<<"enter the size of the file in MB";
	cin>>size;
	file_size=size*1048576;

	total_sector=file_size/sector_size;
	sector_res=(total_sector*4)/sector_size;
	cout<<endl<<"the total no of sector are"<<total_sector<<endl<<"and total no of reserved sector are "<<sector_res;
    char bufferin[512];
    //sec_res=pow(2,14);
    for(i=0;i<512;i++)
    {
    	bufferin[i]='0';
	}

    f.open("this.txt",ios::out);
        for (i=0; i<sector_res; i++)
		 {
          f.write(bufferin,512);
         }
         z=(total_sector-sector_res);
         //cout<<z;
         f.seekp((sector_res+2)*512,ios::beg);
         for(k=0;k<z;k++)
        {


					for(int j=0;j<512;j++)
						{
							if(a>90){

								a=65;}
							bufferin[j]=char (a+j%4);
						}
					a+=4;
				    f.write(bufferin,512);


		}
		current=sector_res*512;
		f.seekp(sector_res*512,ios::beg);//writing root directory
		for(j=0;j<2;j++)
		{

		for(int i=0;i<512;i++)
		{
			bufferin[i]=' ';
		}
		f.write(bufferin,512);
	}
		/*structure s;
	s.name[0]='r';
	s.name[1]='o';
	s.name[2]='o';
	s.name[3]='t';
		for(i=strlen(s.name);i<sizeof(s.name);i++)
		{

		s.name[i]=' ';//appending root directory name with spaces
		}
		s.t='d';
		sprintf(s.size,"%d",4);
		//s.size=4;
		//cout<<"the value of sector_res is"<<sector_res;

		int temp1=sector_res*512;
		cout<<"Temp1 : "<<temp1<<endl;
		sprintf(s.s_pos,"%d",temp1);
		current=atoi(s.s_pos);
		int temp2=sector_res*512+512;
		sprintf(s.e_pos,"%d",temp2);
		//s.e_pos=s.s_pos+512;
		f.write(s.name,sizeof(s.name));
		f<<s.t;
		f.write(s.size,sizeof(s.size));
		f.write(s.s_pos,sizeof(s.s_pos));
		f.write(s.e_pos,sizeof(s.e_pos));*/



        f.close();
}
/*void check_freesec()
{	int i,j=0;
	int arr[5];
	if(req==f)
	{
	f.seekg(8,ios::beg);
	f.read(bufferin,512);
	while(i<sector_res*512)
	{
		u.str[0]=bufferin[i];
		u.str[1]=bufferin[i+1];
		u.str[2]=bufferin[i+2];
		u.str[3]=bufferin[i+3];
		if(u.str[3]=='0')
		{
			arr[j]=i;
			j=j+1;
		}
		i=i+4;
	}
	}
}*/
int checksector_status(int sectorno)  //function for status of sector
{
	int mark_pos,res,area_array;
	char bufferin[512];
	fstream f;
	f.open("this.txt",ios::in);
	/*mark_pos=ceil(sectorno/128);
	res=(512*(mark_pos-1));
	f.seekg(res,ios::beg);
	f.read(bufferin,512);
	area_array=(sectorno-(mark_pos*128))*4-1;*/
	res=sectorno-sector_res;
	if(res<=0)
	return 2;
	else
	{

	mark_pos=(res-1)*4;
	f.seekg(mark_pos,ios::beg);
	f.read(u.str,4);

	//f>>u.var;
	//cout<<"value uvar"<<u.var;
	//cout<<"value of u"<<u.str[3];
	if(u.str[3]=='1')
	{//cout<<"sector is busy";
	f.close();
	return 1;
	}
	else
	{
	//cout<<"sector is free";
	f.close();
	return 0;
	}
}

}
void read_sec(int sector_no)
{	fstream fp;
	fp.open("this.txt",ios::in);
	int buffersize=512;
	int res,mark_pos;
	res=sector_no-sector_res;

	if(res<=0)
	{cout<<"the sector is a reserved sector";
	}
	else{
			int a=65,index;
			fp.seekg((sector_no-1)*buffersize);
			fp.read(bufferin,512);
			//for(int m=0;m<512;m++)
			//cout<<bufferin[m];
		}
		fp.close();
}

void mark_sec(int sectorno)
{
	int total_sector,z,k;
	int i,j,a=65,sector_size=512;
	//total_sector=file_size/sector_size;
	//sector_res=(total_sector*4)/sector_size;
	int res;
	int mark_pos;
	res=sectorno-sector_res;
	//cout<<"res is "<<res<<sector_res;
	int rel_pos,thiss;
	char bufferin[512];
	//cout<<endl<<"the value of res is "<<res;
	//cout<<sector_res;
	if(res<=0)
	{cout<<"the sector is a reserved sector";
	}
	else
	{

		thiss=res/128;
		f.open("this.txt",ios::in|ios::out);
		f.seekg(thiss*512,ios::beg);
		f.read(bufferin,512);
		rel_pos=((res%128)*4)-1;
		//cout<<endl<<"real pos is"<<rel_pos;
		bufferin[rel_pos]='1';
		f.seekp(thiss*512,ios::beg);
		f.write(bufferin,512);
		f.close();



		/*
		u.str[0]='0';
		u.str[1]='0';
		u.str[2]='0';
		u.str[3]='1';
		mark_pos=(res-1)*4;
		f.open("this.txt",ios::in|ios::out);
		f.seekp(mark_pos,ios::beg);
		//cout<<"the value of var is "<<u.var;
		f.write(u.str,4);
		f.close();
		//cout<<endl<<"the statements has been executed";*/
	}


}
void unmark_sec(int sector_no)
{
	int res,mark_pos;
	res=sector_no-sector_res;
	if(res<=0)
	{cout<<"the sector is a reserved sector";
	}
	else
	{

		u.str[0]='0';
		u.str[1]='0';
		u.str[2]='0';
		u.str[3]='1';
		mark_pos=(res-1)*4;
		f.open("this.txt",ios::in|ios::out);
		f.seekp(mark_pos,ios::beg);
		f.write(u.str,4);
		f.close();
	}

}

void write_sec(int sector_no, char ch,int type=0)
{

	fstream fp;
	const int buffersize=512;
	char filename[50],x='2';
	//char bufferIn[buffersize];
	char bufferOut[buffersize];
	int a=65,index,sector_status;
		int res;
	int mark_pos;
	res=sector_no-sector_res;
	//cout<<endl<<"the value of res is "<<res;
	//cout<<sector_res;
	if(res<=0)
	{cout<<"the sector is a reserved sector";
	}
	else
	{

	//sector_status=checksector_status(sector_no);
	if(sector_status==1)
	{
		cout<<"the sector is busy it cannot be overwritten";
	}
	else
	{

	fp.open("this.txt",ios::in|ios::out);
	//cout<<"enter sector number that is to be rewrite: ";

	if(type!=1)
	{
	for(int n=0;n<512;n++)
	{
		bufferOut[n]=ch;
		bufferin[n]=bufferOut[n];
	}
	}
	cout<<endl;
	fp.seekp((sector_no-1)*buffersize);

	fp.write(bufferin,512);
	//fp.seekg((sector_no-1)*buffersize);
	//fp.read(bufferOut,512);
	//for(int m=0;m<512;m++)
		//cout<<bufferOut[m];
	cout<<endl;
	fp.close();

	}}
}
void display_sec(int sector_no)
{
	fstream fp;
	fp.open("this.txt",ios::in);
	int buffersize=512;
	int res,mark_pos;
	res=sector_no-sector_res;

	if(res<=0)
	{cout<<"the sector is a reserved sector";
	}
	else{
			int a=65,index;
			fp.seekg((sector_no-1)*buffersize);
			fp.read(bufferin,512);
			for(int m=0;m<512;m++)
			cout<<bufferin[m];
		}
		fp.close();
}
void display_file()
{
	cout<<"enter file name to be read: ";
	cin>>t.name;

		//cout<<bufferin[i];
	read_sec(current/512+1);
	cout<<endl;

for(int i=0;i<512;i+=32)
	{
		for(int j=0;j<32;j++)
		{
			entry.str[j]=bufferin[i+j];
		}
		if(!strcmp(entry.fd.name,t.name))
		{
	//current=atoi(entry.fd.s_pos);
	//cout<<endl<<"current directory is\t "<<entry.fd.name<<endl;
			//char temp1[4];
			//for (int i =0; i<4;i++)
				//temp1[i]=entry.fd.s_pos[i];
			//strcpy(temp1,entry.fd.s_pos);
			int temp=entry.fd.s_pos;
		read_sec(temp/512+1);
		display_sec(temp/512+1);
		break;
		}
	}

}

int *check_freesec(int type=1)
{	int i=0,sectorno;
	static int r[4];
	//char bufferin[512];
	//f.read(bufferin,512);
	sectorno=sector_res+3;
	while(i<type)
	{
		if(!checksector_status(sectorno))

		{r[i]=sectorno;
		mark_sec(sectorno);
		sectorno=sectorno+1;
		//cout<<endl<<"array values"<<r[i];
		i=i+1;

		}
		else
		{
		sectorno=sectorno+1;}

	}
	return r;

}

void create_file()
{	fstream f;
    struct structure t;
	f.open("this.txt",ios::in | ios::out);
	int *arr,i,j,n,entry_made;
	int k=0;
	string s;
	cout<<"enter the name of file: ";
	cin>>t.name;
	cout<<"enter the data of file: ";
	cin.ignore();
	scanf("%c",&s);
	t.t='f';
	int current_temp=current;
	t.size=s.length();

	//cout<<"the ending position is "<<t.e_pos;

	read_sec((current/512+1));
//cout<<"value of current sector is"<<current/512+1;
		for(int i=0;i<512;i+=32)
	{

		for(int j=0;j<32;j++)
		{
			entry.str[j]=bufferin[i+j];
		}
		if(strcmp(t.name,entry.fd.name)==0)
				{
					cout<<"file already exist";
					//for(i=0)
					f.close();
					return;

				}
			if(entry.fd.t=='d'||entry.fd.t=='f')
					{
					continue;
					}

			else
			{
				arr=check_freesec(strlen(s.c_str())/512+1);
				t.s_pos=((arr[0]-1)*512);
				//cout<<endl<<"starting pos is"<<t.s_pos;
				n=(strlen(s.c_str())/512);
				//cout<<"value of n is"<<endl<<n;
				t.e_pos=(arr[n]*512);
				strcpy(entry.fd.name,t.name);
				entry.fd.t=t.t;
				entry.fd.size= t.size;
				entry.fd.s_pos=t.s_pos;
				entry.fd.e_pos=t.e_pos;
				current=current_temp;
				for(int m=0;m<32;m++)
				bufferin[i+m]=entry.str[m];
				entry_made=1;
				write_sec(current/512+1,'d',1);
				break;

			}


	}

	for(int i=0;i<strlen(s.c_str())/512+1;i++)
{
	f.seekp((*(arr+i)-1)*512,ios::beg);
	for(j=0;j<512;j++)
	f<<' ';
	f.seekp((*(arr+i)-1)*512,ios::beg);
		for(j=0;j<512 && k<strlen(s.c_str());j++)
	{
		f<<s[k];
		k=k+1;
	}
	k=k+512;

}
f.close();
}

void create_dir()
{
	fstream f;
	f.open("this.txt",ios::in|ios::out);
	int current_temp=current;
	string s;
	int *arr,m,i,entry_made;
	char ch;
	cout<<"enter the name of directory: ";
	cin>>t.name;
	t.t='d';
	t.size=0;
	//t.size=0;
	//t.s_pos=((*(arr+0)-1)*512);
	//t.e_pos=((*(arr+0))*512);


	read_sec((current/512+1));
	//cout<<"value of current sector is"<<current/512+1;
		for(int i=0;i<512;i+=32)
	{

		for(int j=0;j<32;j++)
		{
			entry.str[j]=bufferin[i+j];
		}
			if(strcmp(t.name,entry.fd.name)==0)
				{
					cout<<"directory already exist";
					f.close();
					return;

				}
			if(entry.fd.t=='d'||entry.fd.t=='f')
					{
						continue;
					}

			else
			{
				arr=check_freesec();
				t.s_pos=((*(arr+0)-1)*512);
				t.e_pos=((*(arr+0))*512);
				strcpy(entry.fd.name,t.name);
				entry.fd.t=t.t;
				entry.fd.size=t.size;
				entry.fd.s_pos=t.s_pos;
				entry.fd.e_pos=t.e_pos;
				current=current_temp;
				for(int m=0;m<32;m++)
				bufferin[i+m]=entry.str[m];
				entry_made=1;
				write_sec(current/512+1,'d',1);
				unmark_sec(*(arr+0));
				write_sec((*arr+0),' ',0);
				mark_sec(*(arr+0));
				f.close();
				return;

			}


	}
f.close();

}
void change_dir()
{
	cout<<"enter directory name to be changed: ";
	cin>>t.name;

		//cout<<bufferin[i];
		if(!strcmp(t.name,"root"))
		current=sector_res*512;

	read_sec(current/512+1);

	for(int i=0;i<512;i+=32)
	{
		for(int j=0;j<32;j++)
		{
			entry.str[j]=bufferin[i+j];
		}
		if(!strcmp(entry.fd.name,t.name))
		{
			current=entry.fd.s_pos;
			cout<<endl<<"current directory is\t "<<entry.fd.name<<endl;
			cout<<"current is"<<current;
			return;
		}
	}
}
void display_dir()
{
	//cout<<"valyeis"<<current/512;
	read_sec(current/512+1);

	//for(int i=0;i<512;i++)
	//cout<<bufferin[i];
	cout<<endl<<"\t\tCONTENT\t\t\tTYPE";
	for(int i=0;i<512;i+=32)
	{
		for(int j=0;j<32;j++)
		{
			entry.str[j]=bufferin[i+j];
		}
		cout<<endl<<"\t\t"<<entry.fd.name<<"\t\t\t"<<entry.fd.t;
		/*if(entry.fd.t=='d')
		cout<<endl<<"directories"<<entry.fd.name<<endl;
		if(entry.fd.t=='f')
		cout<<"files"<<entry.fd.name;*/
	}


}
int main()
{

    int sector_no,y,var;
    int *p;
    char ch;


    sector_set();
    do{

     cout<<endl<<"1.Read sector\n2.Write sector\n3.check sector status\n4.mark sector\n5.unmark sector\n6.exit\n7.display files and directories\n8.create file\n9.create directory\n10.change directory\n11.display file data\n12.display sector\n";
     cout<<endl<<"enter your choice: ";
     cin>>y;


     switch(y)
	 {

     case 1:
     	cout<<"enter the sector no to be read: ";
     	cin>>sector_no;
		read_sec(sector_no);
        break;

     case 2:
     	cout<<"enter the sector no to be written: "<<endl;
     	cin>>sector_no;
     	cout<<endl<<"enter character to be written";
     	cin>>ch;
     	write_sec(sector_no,ch);
        break;

     case 3:
         cout<<"enter the sector no to be checked: ";
         cin>>sector_no;
         var=checksector_status(sector_no);
         if(var==2)
         	cout<<"sector is reserved";
         else if(var==1)
         	cout<<"sector is busy";
         else
         	cout<<"sector is free";
        break;


     case 4:
     	cout<<"enter the sector no to be marked: ";
     	cin>>sector_no;
     	mark_sec(sector_no);
        break;
    case 5:
     	cout<<"enter the sector no: ";
     	cin>>sector_no;
     	unmark_sec(sector_no);
        break;
    case 6:
    	return 0;
    case 7:
    	display_dir();
    	break;
    case 8:
    	cout<<"create new file";
    	create_file();
    	break;
    case 9:
    	cout<<endl<<"calling function check free sector: ";
    	create_dir();
		break;
	case 10:
		change_dir();
		break;
	case 11:
		display_file();
		break;
	case 12:
		cout<<endl<<"enter sector no to be displayed"<<endl;
		cin>>sector_no;
		display_sec(sector_no);
		break;
     default:
        cout<<"enter the correct option"<<endl;
        break;
	}
	/*cout<<endl<<"do you want to continue press y for yes\t";
	cin>>ch;*/
	}
	while(1);
}
