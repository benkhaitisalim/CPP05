#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm",145,137),target("default_shrubbery")
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &file):AForm("ShrubberyCreationForm",145,137),target(file)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other),target(other.target){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(const Bureaucrat& boss) const
{
	if(!getisSigned())
	{
		throw GradeTooLowException();
	}
	if(boss.getGrade() > getRequiredGradeToExecute())
	{
		throw GradeTooLowException();
	}
	std::ofstream ofs(target + "_shrubbery");
	if(!ofs)
	{
		throw std::runtime_error("Failed to open output file");
	}
	ofs << 		" _ - _\n" 
			" 	/~~   ~~\\\n" 
			" /~~       ~~\\\n" 
			"{            }\n" 
			" \\ _-    -_ /\n" 
			" ~  \\\\ // ~\n"
			"_- - | | _- _\n" 
			" _ - | | -_\n" 
			"    // \\\\\n";	
	ofs.close();
}

const char *ShrubberyCreationForm::GradeTooLowExceptions::what() const throw()
{
	return "grade not enogh";
}
