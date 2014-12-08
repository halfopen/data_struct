#include<iostream>
using namespace std;

class Term
{
	int coef;
	int exp;
	Term *link;
	friend ostream& operator<<(ostream&,const Term&);
	friend class Polynominal;
public:
	Term(int c,int e):coef(c),exp(e)
	{
		link=0;	
	}
	Term(int c,int e,Term* nxt):coef(c),exp(e),link(nxt){}
	Term* InsertAfter(int c,int e);
};
Term* Term::InsertAfter(int c,int e)
{
	link=new Term(c,e,link);
	return link;
}
ostream& operator<<(ostream& os,const Term& val)
{
	if(val.coef==0)return os;
	os<<val.coef;
	switch(val.exp)
	{
		case 0:break;
		case 1:os<<"X";break;
		default:os<<"X^"<<val.exp;break;
	}
	return os;
}

class Polynominal
{
	Term* theList;
	friend ostream& operator<<(ostream&,const Polynominal&);
	friend istream& operator>>(istream&, Polynominal&);
	friend Polynominal operator+ (Polynominal&,Polynominal&);
public:
	Polynominal()
	{
		theList=new Term(0,-1);
		theList->link=theList;
	}
	void AddTerms(istream& in);
	void Output(ostream& out)const;
	void PolyAdd(Polynominal& r);
};
void Polynominal::AddTerms(istream& in)
{
	Term* q=theList;
	int c,e;
	for(;;)
	{
		cout<<"input a term(coef,exp):"<<endl;
		in>>c>>e;
		if(e<0)break;
		q=q->InsertAfter(c,e);
	}
}
void Polynominal::Output(ostream& out)const
{
	int first=1;
	Term* p=theList->link;
	cout<<"the polynominal is:"<<endl;
	for(;p!=theList;p=p->link)
	{
		if(!first&&(p->coef>0))
			out<<"+";
		first=0;
		out<<*p;	
	}
	cout<<endl;
}
void Polynominal::PolyAdd(Polynominal& r)
{
	Term* q,*q1=theList,*q2,*p;
	p=r.theList;
	q=q1->link;
	p=p->link;
	while(p->exp>=0)
	{
		while(p->exp<q->exp)
		{
			q1=q;
			q=q->link;
		}
		if(p->exp==q->exp)
		{
			q->coef=p->coef+q->coef;
			if(q->coef==0)
			{
				q2=q;
				q1->link=q->link;
				q=q->link;
				delete q2;
				p=p->link;
			}
			else
			{
				q1=q;
				q=q->link;
				p=p->link;
			}
		}
		else
		{
			q1=q1->InsertAfter(p->coef,p->exp);
			p=p->link;
		}	
	}
}

ostream& operator<< (ostream& out,const Polynominal& x)
{
	x.Output(out);
	return out;
}
istream& operator>> (istream& in, Polynominal& x)
{
	x.AddTerms(in);
	return in;
}
Polynominal operator+(Polynominal &a,Polynominal &b)
{
	a.PolyAdd(b);
	return a;
}
int main()
{
	Polynominal p,q;
	cin>>p;
	cout<<p;
	cin>>q;
	cout<<q;
	q=q+p;
	cout<<q;
	return 0;
}

