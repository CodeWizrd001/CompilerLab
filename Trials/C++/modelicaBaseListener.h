
// Generated from modelica.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "modelicaListener.h"


/**
 * This class provides an empty implementation of modelicaListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  modelicaBaseListener : public modelicaListener {
public:

  virtual void enterProg(modelicaParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(modelicaParser::ProgContext * /*ctx*/) override { }

  virtual void enterExpr(modelicaParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(modelicaParser::ExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

