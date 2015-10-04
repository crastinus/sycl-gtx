#include "specification\ranges\id.h"
#include "data_ref.h"
#include "src_handlers\kernel_source.h"

using namespace cl::sycl;
using namespace detail;

void detail::kernel_add(string_class line) {
	kernel_::source::add(line);
}

const string_class data_ref::open_parenthesis = "(";

string_class data_ref::get_name(id<1> index) {
	return (index.type == data_ref::type_t::id_global ? point_names::id_global : point_names::id_local) + "0";
}

// TODO: local id
string_class data_ref::get_name(id<2> index) {
	return point_names::id_global + point_names::all_suffix;
}
string_class data_ref::get_name(id<3> index) {
	return point_names::id_global + point_names::all_suffix;
}

id_ref::id_ref(int n, size_t* value, type_t access_type)
	:	data_ref(
			(access_type == type_t::id_global ? point_names::id_global : point_names::id_local) + std::to_string(n)
		),
		value(value) {}
