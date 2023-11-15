#include "main.h"
/**
 * tokenize_command - get command tokens
 * @data: program data
 */
void tokenize_command(program_data *data)
{
int i = 1, command_count = 1, length = str_length(data->input);
char *del = " ";

if (length)
data->input[strcspn(data->input, "\n")] = '\0';

while (data->input[length - i] == ' ')
{
data->input[length - i] = '\0';
i++;
}

if (!data->input)
return;

for (i = 0; data->input[i]; i++)
{
if (data->input[i] == del[0])
command_count++;
}

data->command_tokens = malloc((command_count + 1) * sizeof(char *));
if (!data->command_tokens)
{
perror("Error");
exit(errno);
}

i = 0;
data->command_tokens[i] = str_clone(strtok(data->input, del));

while (i < command_count - 1)
{
i++;
data->command_tokens[i] = str_clone(strtok(NULL, del));
}
data->command_tokens[command_count] = NULL;
}
