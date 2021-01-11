
// Generated from modelica.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "modelicaParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by modelicaParser.
 */
class  modelicaListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(modelicaParser::ProgContext *ctx) = 0;
  virtual void exitProg(modelicaParser::ProgContext *ctx) = 0;

  virtual void enterExpr(modelicaParser::ExprContext *ctx) = 0;
  virtual void exitExpr(modelicaParser::ExprContext *ctx) = 0;


};

