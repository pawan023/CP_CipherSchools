// Balanced Parenthesis

bool isBalanced(string x) {
    stack<char> s;
    for(int i=0; i<x.size(); i++){
        if(x[i]=='{' or x[i]=='(' or x[i]=='[') s.push(x[i]);
        else{
            if(!s.empty()){
            	char a=s.top(), b=x[i];
            	if((a=='{'&&b=='}') or (a=='('&&b==')') or (a=='['&&b==']'))
					s.pop();
				else
					return false; 
			}
            else return false;
        }
    }
    return s.empty();
}
