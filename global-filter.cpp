#include <wayfire/plugin.hpp>
#include <wayfire/output.hpp>
#include <string>

using namespace std;

const struct wl_client *first_client=NULL;
string blocked[]={
  "zwlr_foreign_toplevel_manager_v1",
  "zwlr_screencopy_manager_v1"
};

bool myfilter(const struct wl_client *client, __attribute__((unused)) const struct wl_global *global, __attribute__((unused)) void *data)
{
    if (first_client==NULL) first_client=client;
    return (client==first_client ||
      std::find(std::begin(blocked), std::end(blocked), wl_global_get_interface(global)->name) == std::end(blocked));
}

class global_filter : public wf::plugin_interface_t
{
  public:
    void init() override
    {
        wl_display_set_global_filter(wf::get_core().display, myfilter, NULL);
    }

    void fini() override
    {
        wl_display_set_global_filter(wf::get_core().display, NULL, NULL);
    }
};

DECLARE_WAYFIRE_PLUGIN(global_filter);
