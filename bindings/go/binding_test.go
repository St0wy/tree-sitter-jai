package tree_sitter_Jai_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-Jai"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_Jai.Language())
	if language == nil {
		t.Errorf("Error loading Jai grammar")
	}
}
