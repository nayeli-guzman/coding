def missingCharacters(s):
        
    letters = "a b c d e f g h i j k l m n o p q r s t u v w x y z"
    numbers = "0 1 2 3 4 5 6 7 8 9"

    letters = letters.split()
    numbers = numbers.split()

    for i, c in enumerate(s):
        
        
        if c in numbers:
            numbers.remove(c)
        elif c in letters:
            letters.remove(c)
    
    result = ""
    
    for i in numbers:
        if (i != "-"):
            result = result + str(i)
    
    for i in letters:
        if (i != "-"):
            result = result + str(i)
    
    return result
    
    
print(missingCharacters("8hypotheticall024y6wxz"))