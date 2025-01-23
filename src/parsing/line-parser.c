#include "../../includes/parsing.h"
#include "../../includes/containers.h"

static bool is_meta(char c)
{
  return (ft_strchr(METACHARACTER, c) != NULL);
}

static bool is_whitespace(char c)
{
  return (c == ' ' || c == '\t');
}

static bool is_closeable(char c)
{
  return (c == '"' || c == '\'' || c == '\(');
}

// This function iterates the line byte by byte until it encounters either a 
// whitespace, closeable meta ('(', '\'', '\"') or a functional meta ('>', '<', '|')
static char *extract_token(char **line)
{
  char *token;
  char *itr;
  char closeable_match;

  itr = *line;
  while (*itr)
  {
    if (!is_meta(*itr) && !is_closeable(*itr) && !is_whitespace(*itr))
      itr++;
    else if (is_closeable(*itr))
    {
      if (*itr == '\(')
        closeable_match = ')';
      else
        closeable_match = *itr;
      while (*++itr != closeable_match)
        if (!*itr)
          return (NULL);
      break ;
    }
    else
      break ;
  }
  if (is_meta(*itr) && itr == *line)
    token = ft_substr(*line, 0, 1);
  else if (is_meta(*itr) && itr != *line)
    token = ft_substr(*line, 0, --itr - *line + 1);
  else
    token = ft_substr(*line, 0, itr - *line + 1);
  *line = itr + 1;
  return (token);
}

static bool cat_meta(t_dll *dll, t_dll_node *itr, char meta)
{
  char *temp;
  temp = itr->data;
  itr->data = ft_strjoin(temp, itr->next->data);
  free(temp);
  dll_remove(dll, itr->next);
  if (ft_strncmp((char *)itr->next->data, &meta, 1) == 0)
    return (false);
  return (true);
}

/// This function ensures that when a functional metac is seen,
/// it is not preceeded nor postceeded by no command..
bool validate_mc(t_dll *dll, t_dll_node *itr, char meta)
{
  if (ft_strchr(PIPE, meta) || ft_strchr(AMPERSAND, meta))
  {
    printf("%p\n", itr->prev);
    if (!itr->next)
      return (false);
    else if (!itr->prev || ft_strchr(METACHARACTER, *(char *)itr->prev->data))
      return (false);
    if (ft_strncmp((char *)itr->next->data, &meta, 1) == 0)
      return (cat_meta(dll, itr, meta));
    else if (ft_strchr(AMPERSAND, meta))
      return (false);
  }
  else if (ft_strchr(OA, meta) || ft_strchr(CA, meta))
  {
    if (!itr->next)
      return (false);
    if (ft_strncmp((char *)itr->next->data, &meta, 1) == 0)
      return (cat_meta(dll, itr, meta));
  }
  return (true);
}

/// This analyzes the tokens to determine if any metacs that 
/// were seen are used grammatically correct.
bool token_analysis(t_dll *dll)
{
  t_dll_node *itr;

  if (dll->len == 0)
    return (false);
  itr = dll->head;
  while (itr)
  {
    if (!validate_mc(dll, itr, *(char *)itr->data))
      return (false);
    itr = itr->next;
  }
  return (true);
}

/// This function sanitizes any redirection metacs for it's respective
/// grammar.
bool sanity_check(t_dll *dll)
{
  t_dll_node *itr;
  t_dll_node *temp;
  char meta;

  itr = dll->head;
  while (itr)
  {
    temp = itr->next;
    if (is_whitespace(*(char *)itr->data))
      dll_remove(dll, itr);
    itr = temp;
  }
  itr = dll->head;
  while (itr)
  {
    meta = *(char *)itr->data;
    if (ft_strchr(OA, meta) || ft_strchr(CA, meta))
      if (ft_strchr(&meta, *(char *)itr->next->data))
        return (false);
    itr = itr->next;
  }
  return (true);
}

bool parse_line(t_dll *dll, char *line)
{
  char *token;

  while (line)
  {
    token = extract_token(&line);
    if (!token)
      return (false);
    if (!*token)
      break ;
    dll_append(dll, token);
  }
  if (!token_analysis(dll))
    return (false);
  return (sanity_check(dll));
}
