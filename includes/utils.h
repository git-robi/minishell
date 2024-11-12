
#ifndef UTILS_H
#define UTILS_H


//free memory
void    free_data_and_exit(t_mini *data, int exit_code);
void    free_lexer_list(t_lexer **lexer_list);
void    free_parser_list(t_parser **parser_list);
void    free_strarr(char **strarr);


#endif
