package tree_sitter_jai_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-jai"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_jai.Language())
	if language == nil {
		t.Errorf("Error loading Jai grammar")
	}
}
