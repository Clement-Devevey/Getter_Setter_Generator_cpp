# Getter_Setter_Generator_cpp
Generate getter and setter for cpp classes. Configure pure virtual and override. Methods inside class defintion are inline by default.

# Table of content
- [Getter\_Setter\_Generator\_cpp](#getter_setter_generator_cpp)
- [Table of content](#table-of-content)
- [Compilation](#compilation)
	- [using QT Creator](#using-qt-creator)
	- [using command line](#using-command-line)
- [Usage](#usage)
- [Results](#results)
- [TODO](#todo)

# Compilation
## using QT Creator
Simply link CMake to the project.

## using command line
- Requires Boost library
- ```g++ boost_main.cpp Variables.cpp -o boost_main.exe -lboost_program_options```

# Usage
```./GetterSetterGenerator -v MyClass1:m_var1 MyClass2:m_var2 [-o] [-p] [-h]```


# Results
```c++
override set to 1
pure-virtual set to 1
VARIABLES DETECTED: 
/*
* @return var1
*/
virtual MyClass1 getVar1() const = 0;

/*
* Définit var1
* @param var1
*/
virtual void setVar1(MyClass1 const& var1) = 0;

/*
* @return var2
*/
virtual MyClass2 getVar2() const = 0;

/*
* Définit var2
* @param var2
*/
virtual void setVar2(MyClass2 const& var2) = 0;

/*
* Définit var1
* @param var1
*/
MyClass1 getVar1() const override
{
	 return m_var1;
}

/*
* @return var1
*/
void setVar1(MyClass1 const& var1) override
{
	m_var1 = var1;
}

/*
* Définit var2
* @param var2
*/
MyClass2 getVar2() const override
{
	 return m_var2;
}

/*
* @return var2
*/
void setVar2(MyClass2 const& var2) override
{
	m_var2 = var2;
}

```
# TODO
- [x] Rewrite prog using boost.Program_options
- [x] Support args option --override=true
- [x] Support args option --pure-virtual=true
- [x] Display all virtual methods first then others
