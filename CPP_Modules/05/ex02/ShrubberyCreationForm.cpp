#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137)
	, target_("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) 
	: AForm("ShrubberyCreationForm", 145, 137)
	, target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm(other)
	, target_(other.target_)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
      this->target_ = other.target_;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { 
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	std::string tree = R"(
                                                         .
                                              .         ;  
                 .              .              ;%     ;;   
                   ,           ,                :;%  %;   
                    :         ;                   :;%;'     .,   
           ,.        %;     %;            ;        %;'    ,;
             ;       ;%;  %%;        ,     %;    ;%;    ,%'
              %;       %;%;      ,  ;       %;  ;%;   ,%;' 
               ;%;      %;        ;%;        % ;%;  ,%;'
                `%;.     ;%;     %;'         `;%%;.%;'
                 `:;%.    ;%%. %@;        %; ;@%;%'
                    `:%;.  :;bd%;          %;@%;'
                      `@%:.  :;%.         ;@@%;'   
                        `@%.  `;@%.      ;@@%;         
                          `@%%. `@%%    ;@@%;        
                            ;@%. :@%%  %@@%;       
                              %@bd%%%bd%%:;     
                                #@%%%%%:;;
                                %@@%%%::;
                                %@@@%(o);  . '         
                                %@@@o%;:(.,'         
                            `.. %@@@o%::;         
                               `)@@@o%::;         
                                %@@(o)::;        
                               .%@@@@%::;         
                               ;%@@@@%::;.          
                              ;%@@@@%%:;;;. 
                          ...;%@@@@@%%:;;;;,..    
credit: Gilo97 @ ascii.co.uk/art/tree
)";
	std::filesystem::path file = _target + "_shrubbery";
	std::ofstream outstream(file, std::ios::binary);
	if (!outstream.is_open())
		throw std::exception();
	outstream << tree; 
}
