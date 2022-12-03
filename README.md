# Getter_Setter_Generator_cpp
Generate getter and setter for cpp classes.

# Compilation
```g++ main.cpp -o main```

# Usage
```./main MyClass1 m_var1 MyClass2 m_var2```

# Results

```c++/*
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
}```
