public class ClipboardExample {
    public class Clipboard {
        private String value;
            public void copy(String value) {
            this.value = value;
        }
        public String paste() {
            return value;
        }
    }

    public static void main(String[] args) {
        ClipboardExample temp = new ClipboardExample();
        Clipboard clipboard1 = temp.new Clipboard();
        Clipboard clipboard2 = temp.new Clipboard();
        clipboard1.copy("Java");
        clipboard2.copy("Design patterns");
        clipboard1.copy("Temp");
        System.out.println(clipboard1.paste());
        System.out.println(clipboard2.paste());
    }
}