class Ch
{
    private char ch;

    public Ch(char ch)
    {
        this.ch = ch;
    }

    public char getCh()
    {
        return ch;
    }
}

class Word
{
    private String word;

    public Word(String word)
    {
        this.word = word;
    }

    public String getWord()
    {
        return word;
    }
}


public class Quiz
{
    public static int countChar(Word word, Ch character)
    {
        int count = 0;
        
        for(int i=0; i<word.getWord().length(); i++)
        {
            if(character.getCh() == word.getWord().charAt(i))
            {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args)
    {
        int charCount = countChar(new Word("hello"), new Ch('h'));
        System.out.println(charCount);
    }
}
