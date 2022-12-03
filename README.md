[ToC]

# Getter_Setter_Generator_cpp
Generate getter and setter for cpp classes.

# Compilation
## V1
```g++ main.cpp -o main```

## V2
- Requires Boost library
```g++ boost_main.cpp Variables.cpp -o boost_main.exe -lboost_program_options```

# Usage
## V1
```./main MyClass1 m_var1 MyClass2 m_var2```

## V2
```./boost_main.exe -v MyClasse1:m_var1 MyClasse2:m_var2```

# Results
## V1
```c++
/*
* Définit var1
* @param var1
*/
void setVar1(MyClass1 const& var1)
{
	m_var1 = var1;
}

/*
* @return m_var1
*/

MyClass1 getVar1() const
{
	 return m_var1;
}

/*
* Définit var2
* @param var2
*/
void setVar2(MyClass2 const& var2)
{
	m_var2 = var2;
}


/*
* @return m_var2
*/
MyClass2 getVar2() const
{
	 return m_var2;
}
```

## V2
```c++
/*
* Définit var1
* @param var1
*/
void setVar1(MyClasse1 const& var1)
{
	m_var1 = var1;
}

/*
* @return var1
*/
MyClasse1 getVar1() const
{
	 return m_var1;
}

/*
* Définit var2
* @param var2
*/
void setVar2(MyClasse2 const& var2)
{
	m_var2 = var2;
}

/*
* @return var2
*/
MyClasse2 getVar2() const
{
	 return m_var2;
}
```
# TODO
[x] Rewrite prog using boost.Program_options
[ ] Support args option --override=true
[ ] Support args option --pure-virtual=true
