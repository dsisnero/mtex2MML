#include "clar.h"
#include "clar_test.h"
#include <stdio.h>
#include <string.h>

static char *fixture_tex;
static char *fixture_mml;
static char *result;

void test_numbered_equations__initialize(void)
{
  global_test_counter++;
}

void test_numbered_equations__cleanup(void)
{
  if (fixture_tex != NULL) {
    free(fixture_tex);
  }

  if (fixture_mml != NULL) {
    free(fixture_mml);
  }

  if (result != NULL) {
    free(result);
  }
}

void test_numbered_equations__single_equation(void)
{
  fixture_tex = read_fixture_tex("numbered_equations/single_equation.txt");
  fixture_mml = read_fixture_mml("numbered_equations/single_equation.html");
  result = mtex2MML_global_parse(fixture_tex, strlen(fixture_tex), MTEX2MML_DELIMITER_DEFAULT, 1);

  cl_assert_equal_s(fixture_mml, result);
}

void test_numbered_equations__multiple_equations(void)
{
  fixture_tex = read_fixture_tex("numbered_equations/multiple_equations.txt");
  fixture_mml = read_fixture_mml("numbered_equations/multiple_equations.html");
  mtex2MML_filter(fixture_tex, strlen(fixture_tex), MTEX2MML_DELIMITER_DEFAULT);
  result = mtex2MML_output();

  cl_assert_equal_s(fixture_mml, result);
}

void test_numbered_equations__single_notag(void)
{
  fixture_tex = read_fixture_tex("numbered_equations/single_notag.txt");
  fixture_mml = read_fixture_mml("numbered_equations/single_notag.html");
  result = mtex2MML_global_parse(fixture_tex, strlen(fixture_tex), MTEX2MML_DELIMITER_DEFAULT, 1);

  cl_assert_equal_s(fixture_mml, result);
}

void test_numbered_equations__single_nonumber(void)
{
  fixture_tex = read_fixture_tex("numbered_equations/single_nonumber.txt");
  fixture_mml = read_fixture_mml("numbered_equations/single_nonumber.html");
  result = mtex2MML_global_parse(fixture_tex, strlen(fixture_tex), MTEX2MML_DELIMITER_DEFAULT, 1);

  cl_assert_equal_s(fixture_mml, result);
}

void test_numbered_equations__multiple_notag_nonumber(void)
{
  fixture_tex = read_fixture_tex("numbered_equations/multiple_notag_nonumber.txt");
  fixture_mml = read_fixture_mml("numbered_equations/multiple_notag_nonumber.html");
  result = mtex2MML_global_parse(fixture_tex, strlen(fixture_tex), MTEX2MML_DELIMITER_DEFAULT, 1);

  cl_assert_equal_s(fixture_mml, result);
}

void test_numbered_equations__skip_label(void)
{
  fixture_tex = read_fixture_tex("numbered_equations/skip_label.txt");
  fixture_mml = read_fixture_mml("numbered_equations/skip_label.html");
  result = mtex2MML_global_parse(fixture_tex, strlen(fixture_tex), MTEX2MML_DELIMITER_DEFAULT, 1);

  cl_assert_equal_s(fixture_mml, result);
}

void test_numbered_equations__skip_tag(void)
{
  fixture_tex = read_fixture_tex("numbered_equations/skip_tag.txt");
  fixture_mml = read_fixture_mml("numbered_equations/skip_tag.html");
  result = mtex2MML_global_parse(fixture_tex, strlen(fixture_tex), MTEX2MML_DELIMITER_DEFAULT, 1);

  cl_assert_equal_s(fixture_mml, result);
}
