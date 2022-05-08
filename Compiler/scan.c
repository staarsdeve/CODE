#include"defs.h"
#include"data.h"
#include"decl.h"

//lexical scanning




//return the position of character c
//in stirng c,or -1 ic c not found


static int chrpos(char *s,int c){
	char *p;

	p=strchr(s,c);
	return (p?p-s:-1);
}

//get the next character from the input file



static int next(void){
	int c;

	if(Putback){              //use the character put 
		c=Putback;	  //back if there is one
		Putback=0;
		return c;
	}

	c=fgetc(Infile);
	if(c=='\n'){
		Line++;
	}
	
	return c;
}


//scan and return an integer literal
//value from the input file
//store the value as a string in text
static int scanint(int c){
	int k,val=0;

	//convert each character into an int value
	while((k=chrpos("0123456789",c))>=0){
		val=val*10+k;
		c=next();
	}

	//we hit a non-interger character,put it back
	putback(c);
	return val;
}


//scan and retrun the next token found in the input
//return 1 if token valid, 0 if no token left
int scan(struct token *t){
	int c;

	//skip whitespace
	c=skip();


	//determine the token based in the input character
	switch(c){
		case EOF:
			return (0);
		case '+':
			t->token=TPLUS;























