/*
 * Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
*/

/*
 * Summary:
 *   Copy 't[]' to 's[]', converting all characters like newline and tab into
 *   visible escape sequences
 * Parameters:
 *   s (char[]): array being copied to
 *   t (char[]): array being copied
 * Return Value:
 *   Doesn't return anything. (Note: 's[]' is modified in place)
 * Description:
 *   Iterate through each character in 't[]' and copy it to 's[]'. When an
 *   escape sequence is encountered, write its visible representation to 's[]'
*/
void escape (char s[], char t[])
{
    int j = 0;
    for (int i = 0; t[i] != '\0'; i++) {
        switch(t[i]) {
            case '\a':
                s[j] = '\\';
                s[++j] = 'a';
                break;
            case '\b':
                s[j] = '\\';
                s[++j] = 'b';
                break;
            case '\f':
                s[j] = '\\';
                s[++j] = 'f';
                break;
            case '\n':
                s[j] = '\\';
                s[++j] = 'n';
                break;
            case '\r':
                s[j] = '\\';
                s[++j] = 'r';
            case '\t':
                s[j] = '\\';
                s[++j] = 't';
                break;
            case '\v':
                s[j] = '\\';
                s[++j] = 'v';
                break;
            case '\\':
                s[j] = '\\';
                s[++j] = '\\';
                break;
            case '\?':
                s[j] = '\\';
                s[++j] = '?';
                break;
            case '\'':
                s[j] = '\\';
                s[++j] = '\'';
                break;
            case '\"':
                s[j] = '\\';
                s[++j] = '\"';
                break;
            default:
                s[j] = t[i];
                break;
        }

        j += 1;
    }

    s[j] = '\0';
}

/*
 * Summary:
 *   Copy 't[]' to 's[]', converting all escape sequences into their
 *   corresponding characters
 * Parameters:
 *   s (char[]): array being copied to
 *   t (char[]): array being copied
 * Return Value:
 *   Doesn't return anything. (Note: 's[]' is modified in place)
 * Description:
 *   Iterate through each character in 't[]' and copy it to 's[]'. When the
 *   visible representation of an escape sequence is encountered, write the
 *   corresponding character to 's[]'
*/
void unescape (char s[], char t[])
{
    int j = 0;
    for (int i = 0; t[i] != '\0'; i++) {
        switch(t[i]) {
            case '\\':
                switch (t[++i]) {
                    case 'a':
                        s[j] = '\a';
                        break;
                    case 'b':
                        s[j] = '\b';
                        break;
                    case 'f':
                        s[j] = '\f';
                        break;
                    case 'n':
                        s[j] = '\n';
                        break;
                    case 'r':
                        s[j] = '\r';
                        break;
                    case 't':
                        s[j] = '\t';
                        break;
                    case 'v':
                        s[j] = '\v';
                        break;
                    case '\\':
                        s[j] = '\\';
                        break;
                    case '?':
                        s[j] = '\?';
                        break;
                    case '\'':
                        s[j] = '\'';
                        break;
                    case '\"':
                        s[j] = '\"';
                        break;
                    default:
                        s[j] = '\\';
                        s[++j] = t[i];
                        break;
                }
            default:
                s[j] = t[i];
                break;
        }

        j += 1;
    }

    s[j] = '\0';
}
