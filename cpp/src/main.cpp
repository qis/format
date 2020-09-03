#include "main.hpp"

// == 120 =============================================================================================================

namespace test {
namespace detail {

#define ONE 1
#define TWO_OR_THREE 2

#if ONE
#if TWO_OR_THREE
constexpr std::array<int, 4> g_data_on_one_line = { 1, 2, 3, 4 };
#endif
#endif

constexpr std::array<int, 4> g_data_on_multiple_lines = {
  1,
  2,
  3,
  4,
};

struct empty_struct_with_a_very_long_name_to_test_inheritence_break_colon_placement
{};

}  // namespace detail

namespace detail::empty_namespace {}
namespace detail::empty_namespace_with_comment {}  // namespace detail::empty_namespace_with_comment

#define LOG_ERROR_MESSAGE(message)                                                                 \
  std::cout << "error message logged from the application to be displayed to the user:" << message \
            << " (additional information is not available)" << std::endl;

template <typename T>
struct base : public std::vector<std::string>
{};

class test
  : public base<test>,
    public base<detail::empty_struct_with_a_very_long_name_to_test_inheritence_break_colon_placement>
{
public:
  test() {}

  test(const int& a) : a_(a) {}

  test(const int* a, int* b) : a_(*a), b_(*b) {}

  test(int a_long, int c, std::string_view string_that_can_be_parsed_as_an_integer_b_that_triggers_all_arguments)
    : a_(a_long),
      b_(std::atoi(string_that_can_be_parsed_as_an_integer_b_that_triggers_all_arguments.data()))
  {}

  test(
    std::string_view string_that_can_be_parsed_as_an_integer_a_that_cannot_trigger_all_arguments_on_next_line,
    int integer_b)
    : a_(std::atoi(
        &string_that_can_be_parsed_as_an_integer_a_that_cannot_trigger_all_arguments_on_next_line[0])),
      b_(integer_b)
  {}

  test(std::string_view
         string_that_can_be_parsed_as_an_integer_a_that_triggers_all_arguments_on_next_line_because_of_column_limit_a)
    : a_(std::atoi(
        &string_that_can_be_parsed_as_an_integer_a_that_triggers_all_arguments_on_next_line_because_of_column_limit_a
          [0])),
      b_(0)
  {}

  test(
    std::string_view string_that_can_be_parsed_as_an_integer_a,
    std::string_view string_that_can_be_parsed_as_an_integer_b)
    : a_(std::atoi(string_that_can_be_parsed_as_an_integer_a.data())),
      b_(std::atoi(string_that_can_be_parsed_as_an_integer_b.data()))
  {
    if (a_ < 0) {
      throw std::runtime_error(
        "a cannot be less, than zero"
        " "
        "also testing break before multiple strings on a single line");
    }

    const auto alignment_test_for_variable_operators_with_different_lengths_a = a_;  // comment test
    const auto alignment_test_for_variable_operators_with_different_lengths_and_comments_b = b_;  // comment test

    const auto short_variable_name = alignment_test_for_variable_operators_with_different_lengths_a +
      alignment_test_for_variable_operators_with_different_lengths_and_comments_b;

    const auto longer_variable_name_for_column_limit_trigger =
      alignment_test_for_variable_operators_with_different_lengths_a +
      alignment_test_for_variable_operators_with_different_lengths_and_comments_b;

    if (a_ > 2) {
      goto end;
    }

    b_ = longer_variable_name_for_column_limit_trigger;

    const auto data = detail::g_data_on_one_line;

    const auto it1 = std::find_if(data.begin(), data.end(), [](int i) { return true; });

    const auto it2 = std::find_if(
      detail::g_data_on_one_line.begin(), detail::g_data_on_one_line.end(), [](int i) {
        return i > 1 ? true : false;
      });

    const auto it3 = std::find_if(
      detail::g_data_on_one_line.begin(), detail::g_data_on_one_line.end(), [](int i) {
        if (i > 1) {
          return true;
        } else {
          return false;
        }
      });

  end:
  }

  void inline_function() {}
  void inline_function_implemented_separately();

private:
  int a_ = 0;                                // zero
  int b_ = std::numeric_limits<int>::max();  // max
};

inline void test::inline_function_implemented_separately()
{
  throw std::runtime_error("test");
}

}  // namespace test

int main(int argc, char* argv[])
{
  do {
    argc++;
  } while ((argc < 1));

  switch (argc) {
  case 0:
    break;
  case 1: {
    LOG_ERROR_MESSAGE("suspicious argc value");
    break;
  }
  }

  return 0;
}