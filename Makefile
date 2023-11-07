################################################################################
# Variable definitions
################################################################################

# Executable names
PROJECT = project
GTEST = test_${PROJECT}

# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++17
CXXFLAGS= ${CXXVERSION} -g
CXXWITHCOVERAGEFLAGS = ${CXXFLAGS} -fprofile-arcs -ftest-coverage
LINKFLAGS= -lgtest

# Directories
SRC_DIR = src
ENTITY_SRC_DIR = src/entity
PROJECT_SRC_DIR = src/project
MANAGER_SRC_DIR = src/manager
GTEST_DIR = test
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

# Tool variables
GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage
STATIC_ANALYSIS = cppcheck
STYLE_CHECK = cpplint
DESIGN_DIR = docs/design
DOXY_DIR = docs/code

################################################################################
# Targets
################################################################################

# Default goal
.DEFAULT_GOAL := compileProject

################################################################################
# Clean-up targets
################################################################################

.PHONY: clean-cov
clean-cov:
	rm -rf *.gcov *.gcda *.gcno ${COVERAGE_RESULTS} ${COVERAGE_DIR}

.PHONY: clean-docs
clean-docs:
	rm -rf docs/code/html

.PHONY: clean-exec
clean-exec:
	rm -rf ${PROJECT} ${GTEST} ${PROJECT}.exe ${GTEST}.exe

.PHONY: clean-obj
clean-obj:
	rm -rf ${SRC_DIR}/*.o ${ENTITY_SRC_DIR}/*.o

.PHONY: clean-temp
clean-temp:
	rm -rf *~ \#* .\#* \
	${SRC_DIR}/*~ ${SRC_DIR}/\#* ${SRC_DIR}/.\#* \
	${GTEST_DIR}/*~ ${GTEST_DIR}/\#* ${GTEST_DIR}/.\#* \
	${SRC_INCLUDE}/*~ ${SRC_INCLUDE}/\#* ${SRC_INCLUDE}/.\#* \
	${ENTITY_SRC_DIR}/*~ ${ENTITY_SRC_DIR}/\#* ${ENTITY_SRC_DIR}/.\#* \
	${PROJECT_SRC_DIR}/*~ ${PROJECT_SRC_DIR}/\#* ${PROJECT_SRC_DIR}/.\#* \
	${DESIGN_DIR}/*~ ${DESIGN_DIR}/\#* ${DESIGN_DIR}/.\#* \
	*.gcov *.gcda *.gcno 

.PHONY: clean
clean: clean-cov clean-docs clean-exec clean-obj clean-temp

################################################################################
# Compilaton targets
################################################################################

# default rule for compiling .cc to .o
%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

# Compilation targets

${GTEST}: ${GTEST_DIR} ${SRC_DIR} ${ENTITY_SRC_DIR}
	${CXX} ${CXXFLAGS} -o ./${GTEST} ${INCLUDE} \
	${GTEST_DIR}/*.cpp  ${ENTITY_SRC_DIR}/*.cpp ${MANAGER_SRC_DIR}/*.cpp ${LINKFLAGS}

compileProject: ${SRC_DIR} ${ENTITY_SRC_DIR} ${PROJECT_SRC_DIR}
	${CXX} ${CXXVERSION} -o ${PROJECT} ${INCLUDE} \
	${ENTITY_SRC_DIR}/*.cpp ${PROJECT_SRC_DIR}/*.cpp ${MANAGER_SRC_DIR}/*.cpp


################################################################################
# Test targets
################################################################################

# To perform all tests
all: ${GTEST} memcheck coverage docs static style

memcheck: ${GTEST}
	valgrind --tool=memcheck --leak-check=yes --error-exitcode=1 ./${GTEST}

coverage: clean-exec clean-cov
	${CXX} ${CXXWITHCOVERAGEFLAGS} -o ./${GTEST} ${INCLUDE} \
	${GTEST_DIR}/*.cpp ${ENTITY_SRC_DIR}/*.cpp ${MANAGER_SRC_DIR}/*.cpp ${LINKFLAGS}
	./${GTEST}
	${LCOV} --capture --gcov-tool ${GCOV} --directory . --output-file \
	${COVERAGE_RESULTS} --rc lcov_branch_coverage=1
	${LCOV} --extract ${COVERAGE_RESULTS} */*/*/${SRC_DIR}/* -o \
	${COVERAGE_RESULTS}
	genhtml ${COVERAGE_RESULTS} --output-directory ${COVERAGE_DIR}
	make clean-temp

static: ${SRC_DIR} ${ENTITY_SRC_DIR} ${GTEST_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all ${SRC_DIR} ${ENTITY_SRC_DIR} ${GTEST_DIR} \
	${SRC_INCLUDE} --suppress=missingInclude --suppress=unusedFunction:*Test.cpp --error-exitcode=1

style: ${SRC_DIR} ${ENTITY_SRC_DIR} ${GTEST_DIR} ${SRC_INCLUDE} ${PROJECT_SRC_DIR}
	${STYLE_CHECK} ${SRC_DIR}/* ${ENTITY_SRC_DIR}/* ${GTEST_DIR}/* ${SRC_INCLUDE}/* \
	${PROJECT_SRC_DIR}/*

################################################################################
# Documentation target
################################################################################

.PHONY: docs
docs: ${SRC_INCLUDE}
	doxygen ${DOXY_DIR}/doxyfile

################################################################################
# Revision History
################################################################################
# Updated: 2022-12-15 Nicole Wilson <n.wilson@uleth.ca>
#  Removed all references to OS as the pipelines are now running on Ubuntu
################################################################################
# Updated: 2022-10-19 Dr. J. Anvik <john.anvik@uleth.ca>
#  Changed the static command to make the pipeline fail on exit with errors.
################################################################################
# Updated: 2022-09-11 Nicole Wilson <n.wilson@uleth.ca>
#  Added reference to OS in setting of STYLE_CHECK.
#  This is a temporary measure until the pipelines are running on Ubuntu
################################################################################
