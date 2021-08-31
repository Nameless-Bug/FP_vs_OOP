import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

class Person{
    String name;

    public Person(String name){
        this.name = name;
    }

    enum love implements Relatable{
        LOVE;
        public <Person> Person relate(Person p1, Person p2, Class<Person> type) throws NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException {
            Constructor<Person> constructor = type.getConstructor(String.class);
            return constructor.newInstance("LovelyBaby");
        }
    }
}

interface Relatable{
    public <T> T relate(T t1, T t2, Class<T> type) throws NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException;
}

public class Relate {
    public static void main(String[] args) throws InvocationTargetException, NoSuchMethodException, InstantiationException, IllegalAccessException {
        Relatable r = Person.love.LOVE;
        Person p1 = new Person("HandsomeBoy");
        Person p2 = new Person("BeautifulGirl");
        final Person baby = r.relate(p1, p2, Person.class);
        System.out.println(baby.name);

    }
}

