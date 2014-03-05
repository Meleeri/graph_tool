#ifndef GT_UTIL_H
#define GT_UTIL_H

#include <string>
#include <graphviz/gvc.h>

void gt_init_gvplugins(GVC_t *gvc);
const std::string& gt_gendot(const std::string& src);
const std::string& gt_gendot_from_file(const std::string& src);

const std::string& gt_gen_graph(int vertex_count, int edge_count, int weight_min, int weight_max);

#endif //GT_UTIL_H
