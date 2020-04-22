/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include <tools/solidityUpgrade/UpgradeChange.h>
#include <tools/solidityUpgrade/UpgradeSuite.h>

#include <libsolidity/ast/AST.h>
#include <libsolidity/ast/ASTVisitor.h>

namespace solidity::tools
{
/** TODO
* Module that performs analysis on the AST. Finds abstract contracts that are
* not marked as such and adds the `abstract` keyword.
*/

class DotSyntax: public AnalysisUpgrade
{
public:
	using AnalysisUpgrade::AnalysisUpgrade;
	void analyze(frontend::SourceUnit const& _sourceUnit) { _sourceUnit.accept(*this); }
private:
	void endVisit(frontend::FunctionCall const& _expression) override;
};

}
