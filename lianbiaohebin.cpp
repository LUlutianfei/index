/*题目描述
输入两行整数数据，构造为两个有序链表，将其合并为一个有序链表输出。
要求：链表中的数据均为正整数，当输入0或负数时，表示链表结束。
输入
两行数据：
每行若干个数据，以0结束，各个数据间以空格分开。
输出
三行数据： 第一行：第一个有序链表。
第二行：第二个有序链表。
第三行：合并后的有序链表。
样例输入
3 1 9 5 0 
7 4 2 9 8 3 16 0 
样例输出
1 3 5 9 (后有空格)
2 3 4 7 8 9 16 (后有空格)
1 2 3 3 4 5 7 8 9 9 16 (后有空格)
*/
#include<iostream>
using namespace std;
static int n1,n2,a[100];
struct note1
{
	int id1;
	note1 *next1;
};
struct note2
{
	int id2;
	note2 *next2;
};
/*
void input1(note1*&head1)
{ note1*s,*p;
   s=new note1;  
   for(n1=1;;n1++)
   { cin>>s->id1;     
   if(s->id1==0)
	   break;
     if(head1==NULL)
         head1=s;      
     else p->next1=s;     
     p=s;                
     s=new note1;         
   }
   p->next1=NULL;
}
*/
void input1(note1 * & head1)
{ 
	int n;
	n1=0;
	note1 * p, *e;
	while(1)
	{
		cin>>n;
		if (n<=0)
			break;
		else
		{
			n1++;
			p = new note1;
			p->id1	 = n;
			p->next1 = NULL;
			if (head1==NULL)
			{
				head1 = p;
				e = p;
			}
			else
			{
				e->next1 = p;
				e = p;
			}
		}
	}
}
void input2(note2 * & head2)
{ 
	int n;
	n2=0;
	note2 * p, *e;
	while(1)
	{
		cin>>n;
		if (n<=0)
			break;
		else
		{
			n2++;
			p = new note2;
			p->id2	 = n;
			p->next2 = NULL;
			if (head2==NULL)
			{
				head2 = p;
				e = p;
			}
			else
			{
				e->next2 = p;
				e = p;
			}
		}
	}
}
/*
void input2(note2*&head2)
{
	note2*s,*p;
	s=new note2;
	for(n2=1;;n2++)
	{
		cin>>s->id2;
		if(s->id2==0)
			break;
		if(head2==NULL)
			head2=s;
		else
			p->next2=s;
			p=s;
			s=new note2;
	}
	p->next2=NULL;
}
*/
void sort1(note1 *&head1)
{
	note1 *s;
	int x;
	for(int i=1;i<n1;i++)
	{
		s=head1;
		for(int j=0;j<n1-i;j++)
		{
			if(s->id1>s->next1->id1)
			{
				x=s->id1;
				s->id1=s->next1->id1;
				s->next1->id1=x;
			}
			s=s->next1;
		}
	}
}
void sort2(note2 *&head2)
{
	note2 *s;
	int x;
	for(int i=1;i<n2;i++)
	{
		s=head2;
		for(int j=0;j<n2-i;j++)
		{
			if(s->id2>s->next2->id2)
			{
				x=s->id2;
				s->id2=s->next2->id2;
				s->next2->id2=x;
			}
			s=s->next2;
		}
	}
}
void output1(note1*&head1)
{
	note1 *s;
	s=head1;
	for(int i=1;i<=n1;i++)
	{
		a[i]=s->id1;
		cout<<s->id1<<" ";
		s=s->next1;
	}
	cout<<endl;
}
void output2(note2*&head2)
{
	note2 *s;
	s=head2;
	for(int i=1;i<=n2;i++)
	{
		cout<<s->id2<<" ";
		s=s->next2;
	}
	cout<<endl;
}
void allsort(note2 *&head2)
{
	note2 *s,*p,*q;
	s=head2;
	q=head2;
	int j=1,i;
	if(a[1]<head2->id2)
			{
				p=new note2;
				p->id2=a[1];
				p->next2=head2;
				head2=p;
				j=2;
			}
	for(;j<=n1;j++)
	{
		s=head2;
		q=head2;
		for(i=1;i<=n2+j;i++)
		{
			q=s;
			s=s->next2;
			if(i==n2+j)
			{
				s->id2=a[i];
			}
			if(a[j]<=s->id2)
			{
				p=new note2;
				p->id2=a[j];
				q->next2=p;
				p->next2=s;
				break;
			}
		}
	}
}
void outallsort(note2*&head2)
{
	for(int i=1;i<=n1+n2;i++)
	{
		cout<<head2->id2<<" ";
		head2=head2->next2;
	}
}
int main()
{
	
	note1 *head1=NULL;
	note2 *head2=NULL;
	input1(head1);
	input2(head2);
	sort1(head1);
	sort2(head2);
	output1(head1);
	output2(head2);
    allsort(head2);
	outallsort(head2);
}

