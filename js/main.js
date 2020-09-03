var array = [ 1, 2 ];

var array_expanded = [
  1,
  2,
];

var object = { one : 1, two : 2 };

var object_expanded = {
  one : 1,
  two : 2,
};

function test1(a) {}

function test2(a, b) {}

function test3(variable_a, variable_c, string_which_can_be_parsed_as_an_unsigned_integer_line_break)
{}

function test3(
  variable_a, variable_c, variable_d, string_which_can_be_parsed_as_an_unsigned_integer_line_break)
{
  test1(variable_a, variable_c, variable_d, function(i) {
    return i > 0 ? true : false;
  })
}

function test(param)
{
  if (param) {
    console.log(param);
  } else {
    console.log("one" + param + "two");
    console.log(
      "one" +
      "two");
  }

  var a = 0;               // comment alignment test
  var b = Math.max(1, 2);  // comment alignment test

  const alignment_test_for_variable_operators_with_different_lengths_a = a;  // comment test
  const alignment_test_for_variable_operators_with_different_lengths_and_comments_b = b;  // comment test

  const short_variable_name = alignment_test_for_variable_operators_with_different_lengths_a +
    alignment_test_for_variable_operators_with_different_lengths_and_comments_b;

  const longer_variable_name_for_column_limit_trigger =
    alignment_test_for_variable_operators_with_different_lengths_a +
    alignment_test_for_variable_operators_with_different_lengths_and_comments_b;
}

function empty() {}

function main()
{
  try {
    test({ one : 1, two : 2 });

    test({
      one : 1,
      two : 2,
    });

    test([ 1, 2 ]);

    test([
      1,
      2,
    ]);
  }
  catch (e) {
    console.error(e);
  }
}
