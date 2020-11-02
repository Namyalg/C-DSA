infix = input("Enter an expression ")
infix = infix.split(" ")
#print(infix)
expr = ""
stack = []
def precedence(op1, op2):
    if op1 == "^" or op1 == "(":
        return 2
    elif op1 == ")":
        return 4
    elif op1 == "+" or op2 == "-":
        return 1
    elif op2 == "*":
        if op1 in "-+":
            return 2
        return 3
    elif op2 == "/":
        if op1 in "-+":
            return 2
        return 3

def valid(s):
    s = s + [" "]
    #print(s)
    stack = []
    if s[0] in "*-/+^":
        return("Invalid expression")
    for i in range(len(s)):
        if s[i] in "*-/+^" and s[i+1] in  "*-/+^":
            #return (0, "1")
            return("Invalid expression")
        if s[i] in "0123456789" and s[i+1] in  "0123456789":
            return("Invalid expression")
            #return (0 , "2")
        if s[i] == "(":
            stack.append(s[i])
        if s[i] == ")":
            try:
                if stack[-1] != "(":
                    return("Invalid expression")
                    #return 0
                else:
                    stack.pop()
            except:
                return("Invalid expression")
                #return (0, "4")
        else:
            pass
            #print("fine")
    #print(stack)
    if stack == []:
        #print(stack)
        #return("Invalid expression")
        return("Expression is valid")
    #return 0
    return("Invalid expression")

if(valid(infix) == "Expression is valid"):
    print("Expression is valid")
    print("Postfix is : ")
    for i in range(len(infix)):
        if infix[i] not in "+*/^-":
            expr += infix[i] + " "
        elif infix[i] in "+*/^-" and len(stack) == 0:
            stack.append(infix[i])
        elif infix[i] == "(":
            stack.append(infix[i])
        elif infix[i] == ")":
            stack.pop()
        else:
            #print("out ", infix[i])
            try:
                while precedence(infix[i], stack[-1]) in [1,3] and len(stack)!= 0:
                    f = stack.pop()
                    #print("Popped is ", f)
                    expr += f + " "
                stack.append(infix[i])
            except:
                stack.append(infix[i])

    while stack:
        expr += stack.pop() + " "
    print(expr)

else:
    print(valid(infix))