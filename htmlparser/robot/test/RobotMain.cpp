#include <stdio.h>
#include "nsVoidArray.h"
#include "nsIWebShell.h"
#include "nsString.h"
#include "nsRepository.h"
#include "nsParserCIID.h"

#ifdef XP_PC
#define PARSER_DLL "raptorhtmlpars.dll"
#else
#define PARSER_DLL "libraptorhtmlpars.so"
#endif

extern "C" NS_EXPORT int DebugRobot(nsVoidArray * workList, nsIWebShell * ww);

int main(int argc, char **argv)
{
  nsVoidArray * gWorkList = new nsVoidArray();
  int i;
  for (i = 1; i < argc; i++) {
    gWorkList->AppendElement(new nsString(argv[i]));
  }

  static NS_DEFINE_IID(kCParserCID, NS_PARSER_IID);
  NSRepository::RegisterFactory(kCParserCID, PARSER_DLL, PR_FALSE, PR_FALSE);

  return DebugRobot(gWorkList, nsnull);
}

