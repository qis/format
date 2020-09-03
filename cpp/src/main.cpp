#include "main.hpp"

// == 100 ====================================================================================== //
// == 120 ========================================================================================================== //

namespace test {
namespace detail {

#define ONE 1
#define TWO_OR_THREE 2

#if ONE
#  if TWO_OR_THREE
constexpr std::array<int, 4> g_data_on_one_line = { 1, 2, 3, 4 };
#  endif
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
  test()
  {}

  test(const std::size_t& a) : a_(a)
  {}

  test(const std::size_t* a, std::size_t* b) : a_(*a), b_(*b)
  {}

  test(
    std::size_t a,
    std::size_t c,
    std::string_view string_which_can_be_parsed_as_an_unsigned_integer_line_break)
    : a_(a), b_(std::atoi(string_which_can_be_parsed_as_an_unsigned_integer_line_break.data()))
  {}

  test(std::string_view
         string_which_can_be_parsed_as_an_unsigned_integer_with_an_uncomfortable_line_break_after_type)
    : a_(std::atoi(
        string_which_can_be_parsed_as_an_unsigned_integer_with_an_uncomfortable_line_break_after_type
          .data())),
      b_(0)
  {
    if (a_ < 0)
    {
      const auto string = "one two";

      const auto short_string =
        "one two "
        "three";

      const auto long_string =
        "very long string to force a break before "
        "assigment and see how it looks like";

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

    if (a_ > 2)
    {
      goto end;
    }

    b_ = longer_variable_name_for_column_limit_trigger;

    const auto data = detail::g_data_on_one_line;

    const auto it1 = std::find_if(
      data.begin(),
      data.end(),
      [](int i)
      {
        return true;
      });

    const auto it2 = std::find_if(
      detail::g_data_on_one_line.begin(),
      detail::g_data_on_one_line.end(),
      [](int i)
      {
        return i > 1 ? true : false;
      });

    const auto it3 = std::find_if(
      detail::g_data_on_one_line.begin(),
      detail::g_data_on_one_line.end(),
      [](int i)
      {
        if (i > 1)
        {
          return true;
        } else
        {
          return false;
        }
      });

  end:
  }

  void inline_function()
  {}
  void inline_function_implemented_separately();

private:
  std::size_t a_ = 0;                                        // comment alignment test
  std::size_t b_ = std::numeric_limits<std::size_t>::max();  // comment alignment test
};

inline void test::inline_function_implemented_separately()
{
  throw std::runtime_error("test");
}

}  // namespace test

int main(int argc, char* argv[])
{
  try
  {
    do
    {
      argc++;
    } while ((argc < 1));

    switch (argc)
    {
    case 0:
      break;
    case 1: {
      LOG_ERROR_MESSAGE("suspicious argc value");
      break;
    }
    default:
      break;
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
