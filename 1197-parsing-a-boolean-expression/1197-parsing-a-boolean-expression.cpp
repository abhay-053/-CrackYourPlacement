class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;

        stack<char> op;

        for(auto i : expression){
            if(i=='&'|| i=='!' || i=='|')   op.push(i);
            else if ( i=='(' || i=='f' || i=='t')   s.push(i);
            else if(i==')')
            {
        
                bool value = s.top()=='f'?false:true;
                s.pop();

                if(op.top()=='!')
                {
                    op.pop();
                    s.pop();
                    s.push(!value?'t':'f');
                }

                else if(op.top()=='&')
                {
                    while(s.top()!='(')
                    {
                        bool val=s.top()=='f'?false:true;
                        s.pop();
                        value=(value&val);
                    }
                    s.pop();
                    op.pop();
                    s.push(value?'t':'f');
                }
                else if(op.top()=='|')
                {
                    while(s.top()!='(')
                    {
                        bool val=s.top()=='f'?false:true;
                        s.pop();
                        value=(value|val);
                    }
                    s.pop();
                    op.pop();
                    s.push(value?'t':'f');
                }
            }
        }
        return s.top()=='t'?true:false;
    }
};