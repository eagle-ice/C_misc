#include <stdio.h>
#include <locale.h>
#include <libintl.h>

#define _(string) gettext(string)

int main()
{
    setlocale(LC_ALL, "zh_CN");
    bindtextdomain("i18n_test", "language");
    textdomain("i18n_test");
    printf(_("Hello world!\n"));
    return 0;
}
