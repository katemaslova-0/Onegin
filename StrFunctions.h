#ifndef ONEGIN_STRFUNCTIONS_H
#define ONEGIN_STRFUNCTIONS_H

int ReworkedStrcmp (const char * str1, const char * str2); /*улучшенная strcmp - игнорирует разницу
между заглавными и строчными буквами, пропускает пунктуацию*/
int ReverseStrcmp (const char * str1, const char * str2); /*улучшенная strcmp, но сравнивающая с конца*/

#endif //ONEGIN_STRFUNCTIONS_H