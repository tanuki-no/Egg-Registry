#include <iostream>
#include "../include/egg/registry/instance.hpp"

void
dump(
    egg::registry::instance::const_iterator start,
    egg::registry::instance::const_iterator end,
    int level)
{
  using std::cout;
  using std::endl;

  for (auto i  = start; i != end; ++i)
  {
    for (auto l = 0; l < level; ++l)
        cout << "  ";

    cout << "d[" << i->first.to_string() << "] = "
         << i->second.to_string() << endl;

    if (i->second.size())
      dump(
        (*i).second.begin(),
        (*i).second.end(),
        level + 1);
  }
}

int
main(
  const int   argc,
  const char* argv[])
{
  using std::cout;
  using std::endl;
  using std::cerr;

  cout << "Checking registry" << endl;
  cout << "---------------------------------------------------------" << endl;
  {
    egg::registry::instance& r = egg::registry::instance::self();
    cout << "Registry: " << r.to_string() << endl << endl;

    r["cmd"]["configuration"] = "/etc/egg/test.xml";
    r["cmd"]["log"] = 9;
    r["xml"]["test.xml"]["egg"]["trace"] = true;
    r["xml"]["test.xml"]["egg"]["logging"]["path"] = "/var/log/egg/controller.xml";
    r["xml"]["test.xml"]["egg"]["logging"]["level"] = 9;
    r["xml"]["test.xml"]["egg"]["logging"]["size"] = 100 * 1024 * 1024;
    dump(r.begin(), r.end(), 0);
  }
  cout  << "---------------------------------------------------------" << endl
        << "Done." << endl << endl;

  return (0);
}
